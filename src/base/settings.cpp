#include <base/settings.hpp>

#include <base/files.hpp>
#include <base/logger.hpp>

#include <glaze/glaze.hpp>

#include <CTRPluginFramework.hpp>

namespace base
{
	using namespace CTRPluginFramework;

	bool settings::load()
	{
		return load_impl() ? true : reset();
	}

	bool settings::store()
	{
		if (g_files->m_settings.Clear() == File::OPResult::SUCCESS)
		{
			auto dump = glz::write_json(m_options);
			return g_files->m_settings.Write(dump.data(), dump.size()) == File::OPResult::SUCCESS;
		}

		return false;
	}

	bool settings::reset()
	{
		if (g_files->m_settings.Clear() == File::OPResult::SUCCESS)
		{
			auto opts = options{};
			auto dump = glz::write_json(opts);
			if (g_files->m_settings.Write(dump.data(), dump.size()) == File::OPResult::SUCCESS)
			{
				m_options = opts;
				g_logger.debug("Settings reset.");
				return true;
			}
		}

        return false;
	}

	bool settings::load_impl()
	{
		auto result = false;

		if (auto size = g_files->m_settings.GetSize(); size > 0)
		{
			if (auto buffer = new char[size]; buffer != nullptr)
			{
				if (g_files->m_settings.Read(buffer, size) == File::OPResult::SUCCESS)
				{
					if (auto data = glz::read_json<options>(buffer))
					{
						m_options = data.value();
						result = true;
					}
				}

				delete[] buffer;
			}
		}

        return result;
	}
}
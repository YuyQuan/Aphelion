#ifndef APHELION_GRAPHICS_WINDOW
#define APHELION_GRAPHICS_WINDOW

namespace aphelion
{
	namespace graphics
	{
		class Window
		{
		public:
			Window() = default;
			Window(const char* pTitle, const int width, const int height);

			virtual ~Window();

			bool Create(const char* pTitle, const int width, const int height);
			
			void Clear(const float red, const float green, const float blue);
			void Update();
			void Display();
			void Destroy();

			const char* GetTitle() const;

			const int GetWidth() const;
			const int GetHeight() const;

			const bool IsOpen() const;

		private:
			bool PlatformInitialize();

			void PlatformUpdate();
			void PlatformDisplay();
			void PlatformDestroy();

		private:
			const char* m_pTitle;

			int m_width;
			int m_height;

			bool m_isOpen;
		};
	}
}

#endif // APHELION_GRAPHICS_WINDOW

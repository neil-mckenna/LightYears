#pragma once


namespace ly
{
	class Application;

	class World
	{
	public:
		World(Application* owningApp);

		void BeginPlayInternal();
		void UpdateInternal(float dt);

		virtual ~World();


	private:
		Application* m_owningApp;
		bool m_BeginPlay;

		void BeginPlay();
		void Update(float dt);

	};


}
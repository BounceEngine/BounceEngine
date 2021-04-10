/*
Copyright (c) 2021 BoomerDev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "EntityManager.h"

namespace ECS {

	class Entity {
	public:
		Entity() {
			ID = Manager.AddNewEntity();
		}

		const EntityID GetID() const {
			return ID;
		}

		template<typename T, typename... Args>
		void AddComponent(Args&&... args) {
			Manager.AddComponent<T>(ID, std::forward<Args>(args)...);
		}

		template<typename T>
		void AddComponent(T& component) {
			Manager.AddComponent<T>(ID, component);
		}

		template<typename T>
		inline T& GetComponent() {
			return Manager.GetComponent<T>(ID);
		}

		template<typename T>
		inline void RemoveComponent() {
			Manager.RemoveComponent<T>(ID);
		}

		template<typename T>
		inline bool HasComponent() {
			return Manager.HasComponent<T>(ID);
		}

		void Destroy() {
			Manager.DestroyEntity(ID);
		}

	private:
		EntityID ID;
	};
}
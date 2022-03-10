import { createStore } from 'vuex'; 

const store = createStore({
    state() {
        return {
            memories: [
                {
                  id: "m1",
                  title: "Sensor 1",
                  description: "SouthEast",
                  img: "https://cdn-icons-png.flaticon.com/512/2540/2540201.png",
                  status: "yellow"
                }
        
            ]
            
        }
    },
    mutations: {
      addMemory(state,memoryData) {
        const newMemory = {
          id: new Date().toISOString(),
          title: memoryData.title,
          img: memoryData.imageUrl,
          description: memoryData.description,
          status: memoryData.status
        };

        state.memories.unshift(newMemory);
      }
    },
    actions: {
      addMemory(context,memoryData) {
        context.commit('addMemory',memoryData);
      }
    },
    getters: {
        memories(state) {
            return state.memories;
        },
        memory(state) {
          return (memoryId) => {
            return state.memories.find(memory => memory.id === memoryId);
          };
        }
    }
});

export default store;
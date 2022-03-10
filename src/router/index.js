import { createRouter, createWebHistory } from '@ionic/vue-router';
import MemoriesPage from '../pages/MemoriesPage.vue';
import HomePage from '../pages/GridPage.vue'; 

const routes = [
  {
    path: '/',
    redirect: '/homepage'
  },
  {
    path: '/sensors',
    component: MemoriesPage
  },
  {
    path: '/homepage',
    component: HomePage
  },
  {
    path: '/sensors/:id',
    component: () => import('../pages/DiagramsPage.vue')
  },
  {
    path: '/sensors/map',
    component: () => import('../pages/MapSensors.vue')
  },
  {
    path: '/homepage/:id',
    component: () => import ('../pages/SingleDiagramPage.vue')
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router

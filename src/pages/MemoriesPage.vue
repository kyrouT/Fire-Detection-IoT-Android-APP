<template>
  <base-layout page-title="All Sensors" page-default-back-link="/homepage">
    <template v-slot:actions-end>
      <ion-button router-link="/sensors/map">
        <ion-icon slot="icon-only" :icon="add"></ion-icon>
      </ion-button>
      <ion-button  @click="openModal">
        <ion-icon slot="icon-only"  :icon="helpCircle"></ion-icon>
      </ion-button>
    </template> 
    <memories-list :memories="memories"></memories-list>
  </base-layout>   
</template>

<script>
import MemoriesList from '../components/memories/MemoriesList.vue';
import {IonButton, IonIcon, modalController} from '@ionic/vue';
import { add,helpCircle } from 'ionicons/icons';
import ModalComp from '../components/ModalComp.vue';


export default {
  components: {
    MemoriesList,
    IonButton,
    IonIcon
    
    
  },
  setup() {
    const openModal = async () => {
      const modal = await modalController.create({
        component: ModalComp, //Modal is name of the component to render inside ionic modal
      });
      return modal.present();
    };

    return { openModal };
  },
  data() {
    return {add, helpCircle}
  },
  computed: {
    memories() {
      return this.$store.getters.memories;
    }
  }
}
</script>

<style scoped>

</style>
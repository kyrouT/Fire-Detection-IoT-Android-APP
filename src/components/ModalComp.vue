<template>
  <ion-header>
    <ion-toolbar>
      <ion-title>Help</ion-title>
      <ion-icon :icon="closeCircleOutline" size="large" style="margin:10px" slot="end" @click="closeModal"></ion-icon>
    </ion-toolbar>
  </ion-header>
  <ion-content class="ion-padding">
      <h1> <u>Sensors page</u> </h1> 
      <ul>
      <li > <h3>Click on each of the "Sensor 1" to see the values diagrams.</h3> </li>
      <li > <h3>Click on the + button, to add a new Sensor or see the Sensors Map.</h3></li> 
      </ul>
  </ion-content>
</template>

<script>
import { IonContent, IonHeader, IonTitle, IonToolbar,  modalController, IonIcon } from "@ionic/vue";
import { defineComponent } from "vue";
import { closeCircleOutline } from 'ionicons/icons';

export default defineComponent({
  name: "ModalComp",
  data() {
    return{closeCircleOutline}
  },
  components: { IonContent, IonHeader, IonTitle, IonToolbar, IonIcon },
  setup() {
    const closeModal = () => {
      modalController.dismiss();
    };

    return { closeModal };
  }
});
</script>
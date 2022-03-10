<template>
  <ion-header>
    <ion-toolbar>
      <ion-title>Help</ion-title>
      <ion-icon :icon="closeCircleOutline" size="large" style="margin:10px" slot="end" @click="closeModal"></ion-icon>
    </ion-toolbar>
  </ion-header>
  <ion-content class="ion-padding">
      <h1> <u>Map</u> </h1> 
      <ul>
      <li > <h3 style="color:red">Red means a sensor has most likely sensed a fire.</h3> </li>
      <li > <h3 style="color:rgb(192, 192, 19)">Yellow means weather conditions increase fire probability</h3></li> 
      <li > <h3 style="color:blue">Blue means safe</h3></li>
      <li > <h3>Home symbol is your Home/Station</h3> </li> 
      </ul>
      <ion-item-divider></ion-item-divider>
       <h2> <u>Guidelines</u> </h2>
      <ul>
      <li > <h3>Tap on Add sensor when you are placing a new Sensor.</h3> </li>
      <li > <h3>You have to be in 5km range to keep Home Signal</h3></li> 
      </ul>
  </ion-content>
</template>

<script>
import { IonContent, IonHeader, IonTitle, IonToolbar,  modalController, IonIcon, IonItemDivider } from "@ionic/vue";
import { defineComponent } from "vue";
import { closeCircleOutline } from 'ionicons/icons';

export default defineComponent({
  name: "ModalMap",
  data() {
    return{closeCircleOutline}
  },
  components: { IonContent, IonHeader, IonTitle, IonToolbar, IonIcon, IonItemDivider },
  setup() {
    const closeModal = () => {
      modalController.dismiss();
    };

    return { closeModal };
  }
});
</script>
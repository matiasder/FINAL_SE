//4.a

spi_device_handle_t mscp

spi_bus_init(
    SPI2_HOST,
    &bus,
    SPI_DMA_CH_AUTO

):

spi_device_interface_config_t mscp_cfg = {
    .clock_speed_hz = 10000000,//10 Mhz
    .mode = 3, // modo 11
    .spics_io_num = CS_SENSOR
    .queue_size = 1
};

spi_dus_add_device(
    SPI2_HOST,
    &mscp_cfg,
    &mscp

);
 //4.b

 //para escribir al wiper 0
 


 void mscp4132_write_register(uint8_t data){
    uint8_t buf[2];
    buf[0] = 0x00; //command byte
    buf[1] = data; //databyte

    spi_transaction_t t = {
        .lenght = 16,
        .tx_buffer = buf,
    };

    spi_device_transmit(mscp,&t)
 }

 //4.c

 uint8_t mcp4132_read_register(void){
    uint8_t tx[2];
    uint8_t rx[2];

    tx[0] = 0x06;
    tx[1] = 0x00;

    spi_transaction_t t = {
    .lenght = 16,
    .tx_buffer = tx,
    .rx_buffer = rx,

    };

    spi_device_transmit(mscp,&t)

    return rx[1]



 }




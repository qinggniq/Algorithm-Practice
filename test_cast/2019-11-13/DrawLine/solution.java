class Solution{
    public  byte[]  drawLine(byte[] screen,int width,int x1,int x2,int y){
        int start_offset = x1 % 8;
        int first_full_byte = x1 / 8;
        if(start_offset != 0){
            first_full_byte++;
        }
        int end_offset = x2 % 8;
        int last_full_byte = x2 / 8;
        if (end_offset != 7){
            last_full_byte--;
        }
    
        //中间完整字节直接填充0xFF
        for (int i = first_full_byte; i <=last_full_byte; i++) {
            screen[(width / 8) * y + i] = (byte) 0xFF;
        }
    
        //构造开始和结束的掩码
        byte start_mask = (byte)(0xFF >> start_offset);
        byte end_mask = (byte)~(0xFF >> (end_offset+1));
    
        //设定直线起点和终点
        if((x1 / 8) == (x2 / 8)){ //x1 和 x2 在同一字节中
            byte mask = (byte)(start_mask & end_mask);
        } else {
            if (start_offset!=0){
                int byte_num = (width / 8) * y + first_full_byte - 1;
                screen[byte_num] |= start_mask;
            }
            if (end_offset != 7){
                int byte_num = (width / 8) * y + last_full_byte + 1;
                screen[byte_num] |= end_mask;
            }
        }
        return screen;
    }
}

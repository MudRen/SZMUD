// /d/jueqing/midao.c
inherit ROOM;

void create()
{
        set("short","�ܵ�");

        set("long",@LONG
һ���谵���ܵ����ı���������Ϊ����ĺۼ���ǽ��һ֧���ͻ��
���ڡ������࣡���ȼ���š�
LONG );
		
		set("exits",([
			"southeast" : "/d/jueqing/shanlu1",
			]));
        
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		setup();
		replace_program(ROOM);
}


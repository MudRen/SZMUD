// Code of ShenZhou
// road: /zhongnan/yinwutin.c

inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
��������Ϊƽʱȫ����Ӿۼ�֮�ء���֮����ׯ�����£����ȴ
��Ϊ���������ϲ����ֻ��һ�Բ��ٵ��Ӿ���һ�����ںȲ����졣��
���������Ե������ڱȻ����������û�µĻ������ɺ������ֽ��ֽ̡�
������һ�侲�ҡ����������᷿�������Ǳ�������
LONG);

        set("exits",([ 
		 	"west" : __DIR__"jinshi",
                        "north" : __DIR__"bingqifang",
			"south" : __DIR__"yuanneixiaojing5",
                        "east" : __DIR__"liangong1",
                      	]));
	set("cost",1);

        setup();

        replace_program(ROOM);
}

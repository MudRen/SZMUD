//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
�姽���֮����ի���ֳ�ˮ�Ϊһ���Ʒ�����Ӿ�ضԳƲ���֮ͥԺ������
������ͨ�������������ϣ��Գ�ˮΪ���ģ���Ϊ��������������ֱ��Ǿ��㣬
�����ң��������Ȼر�������һ����ʤ��ͥԺ���ſ�ͥǰ��һ��׳��ï�ĹŻ���
�ഫ����ǧ�꣬ͥ�����ſ¡�
LONG
	);
	set("cost", 2);
	
     
	set("exits", ([
                "southwest" : __DIR__"dongmen",
                "north" : __DIR__"houmen",
                "southeast" : __DIR__"haopu",
                ]));
	
	
	setup();
	replace_program(ROOM);
}

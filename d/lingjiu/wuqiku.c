//ROOM: wuqiku.c

inherit ROOM;

void create()
{
        set("short", "ޤ����");
        set("long",@LONG
���ǡ����չ������ӵı����⣬�㻷�����ܣ�����ǽ��Ƕ���˸�ʽ��
������ϸһ����ԭ����ǽ���ھ������������֮�οٳ����ӣ����о�����
���ڡ��㲻�ɰ��ޣ����þ��µ��뷨����
LONG       );
        set("exits", ([
		"east" : __DIR__"changl5",
        ]));
        set("objects",([
		"/d/lingjiu/obj/zhujian" : 4,
		"/d/lingjiu/obj/changjian" : 2,
       	]));
        setup();
        replace_program(ROOM);
}

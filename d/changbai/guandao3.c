// Code of ShenZhou
// Room: /guandao3.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������ͨ������Ĺٵ������׿��Ĵ����ȫ���ɻ����̳ɣ��ɲ�������
������������ӵ���������ǽ����ؿڵıؾ�֮·��·��������Ⱥ�����˶���
��������Ƥ����ҩ�ĵ������ˡ�ż���йٱ������ɳ۶�����
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"guandao2",
		"northeast" : __DIR__"ningyuan",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

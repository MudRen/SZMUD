// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ����һ��Сɽ��һ����ӨӨ�ĺ�ˮ��ת�˼����䣬��ض���
÷�����ϸ�б�ᣬ֦Ҷï�ܣ��������÷��ʢ��֮�գ���ѩ�纣����Ȼ
���Ͳ�����
LONG
        );
        set("exits", ([
		"west" : "/d/hangzhou/suti4",
		"east" : __DIR__"mzgate"
	]));

        set("no_clean_up", 0);

	set("cost", 2);
	setup();
	set("outdoors","quanzhou");
	replace_program(ROOM);
}



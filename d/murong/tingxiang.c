// Code of ShenZhou
// Room: /d/murong/tingxiang
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����ˮ�");
	set("long", @LONG
    ˮ�ǰ�����Ҵ�������������������ֱ��ĺ�������ϴ�����
����������Ƚ���ߺ�ȣ������⾫�����ŵ����ľʵ�Ǵ�󲻳�
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo1",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

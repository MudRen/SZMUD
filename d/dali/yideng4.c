// Code of ShenZhou
// yideng quest room 4

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽ�İ�������ǰ��ɫ�续����Ϫ������ˮ��ƽ��֮������
�ƶ�ס��������Ϫˮ��Լ�������Դ�����ˮ������֮���ֲ������
���������ڴ����һ�ʢ��֮ʱ�����һƬ���壬����ҫ�ۡ���ʱ����
�һ�����ˮ������һ�Դ԰�ɫС������������������Լ�ʱ�з�����
����ɽ��һ���ֱ۴�ϸ�ĳ��٣��ط���ϡ���ͷ��������ɽ����ϰ�
����������֮�У���֪�嶥���ж�ߡ�
LONG
	);

    set("no_sleep_room",1);
    set("objects", ([
		"/kungfu/class/dali/woodcutter" : 1,
        ]));

	set("exits", ([
		"up"  : __DIR__"yideng5",
		"out" : __DIR__"maze1",
        ]));

	set("invalid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" && objectp(present("qiao fu", environment(me))))
        return notify_fail("�Է�һ�۲����ĵ�������ǰ��\n");
	return ::valid_leave(me, dir);
}


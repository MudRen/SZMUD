// Code of ShenZhou
// shijie1.c ��ʯ��
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�Ѿ��Ƕ���ɽ�����ˡ�����һ��ͨ�����ҵ���ʯ�ף�����������Σ�����
ʮ�����¡����Ϸ�ͨ����گ�Ĵ���������ߺ������˴��˸�С���
LONG
        );
        set("exits", ([
		"southup" : __DIR__"baoguomen",
                "northeast" : __DIR__"shijie2",
		"west" : __DIR__"shack",
		"southwest" : "/d/dali/guandao6",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 2);
        setup();
//	replace_program(ROOM);
}


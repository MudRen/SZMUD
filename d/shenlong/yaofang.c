// Code of ShenZhou
// ҩ�� /d/shenlong/yaofang
// ALN Sep / 97

inherit ROOM;

void create()
{
	set("short", "ҩ��");
        set("long", @LONG
����½����ҩ������ǽ���������ӣ������з���������в�ҩ��½��
������������ϵ�����ץҩ�����Ρ�������������½���ҪһЩ�ۻ��Ա�
�⵺�ϵĶ������š�
LONG
        );

	set("exits", ([
                "north" : __DIR__"zhulin1",
        ]));

	set("objects", ([
               "/kungfu/class/shenlong/lu" : 1,
	]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}











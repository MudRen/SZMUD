//Modified by Lisser
// Room: zoulang1.c ���ȣ�
// qfy July 7, 1996.

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "����");
    set("long", @LONG
�������Զ��а�ǽ�������ǰ������������������ѧ�����������
���ҡ����ϱ�Ҳ������ң���ѧ���ɵ������书��
LONG
    );

    set("exits", ([
	"east" : __DIR__"qianting",
	"west" : __DIR__"zhengting",
	"northeast" : __DIR__"qingjiao1",
	"southwest" : __DIR__"qingjiao2",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

// Code of ShenZhou
inherit ROOM;

void create()
{
        set("short", "����̨��");
        set("long", @LONG
������ǵ��㣨̨����������С�����ܶ��Ǵ󺣡�������һ��
����(dengta)�����»�����̫���졣
LONG
        );
        
	set("exits", ([
		"northwest" : __DIR__"sea3",
	]));

	set("item_desc", ([
		"dengta" : "һ������бб�ĵ���������ը(zha)����\n"
	]));

        set("objects", ([
          	__DIR__"npc/langren" : 5,
	]));

	set("cost", 4);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dagu", "zha");
}

int do_dagu(string arg)
{
	object me = this_player();

	if ( !arg ) return notify_fail("��Ҫըʲô��\n");
	if (arg != "dengta") 
		return notify_fail("�������ը��\n");
	if (objectp(present("lang ren",environment(me))))
                return notify_fail("�ձ����˰ε���ס����\n");
        CHANNEL_D->do_channel(me,"rumor",
           sprintf("%s��ըҩ���ڵ����£�ֻ�����䡹��һ�����죬�������ձ������������졣", 
           me->name()));
        set("long", @LONG
������ǵ��㣨̨����������С�����ܶ��Ǵ󺣡����ϵĵ���
��ը���ˡ�
LONG
        );


	return 1;
}

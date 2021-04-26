// Code of ShenZhou
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	object ob;

        set("short", "¹ҰԷ");
        set("long", @LONG
һ����������������Ī���·���ӿ������С·��Ȼ���ʣ����
��ǰ����һ�鳤������ݺͲ�֦ʲ�������֣���ֻ¹��Ծ����С��߽�
���֣���Ҷ��ϥ�һ��˫������䣬����һ����(lianzuo)��������
ᦸǡ�������¹���ʯ��������ʢ���㻨����ľ��
LONG
        );

        set("exits", ([
                "east" : __DIR__"wangyou",
        ]));
        set("item_desc", ([
                "lianzuo" : "�������м�����̳����档\n",
        ]));
	set("cost", 2);
        set("outdoors","qilian-shan");
        setup();
	ob=new("/d/qilian/obj/lx-jing");
	if (ob)
	ob->move(__DIR__"luyeyuan");
}

void init()
{
        add_action("do_sit", "sit");
	add_action("do_stand", "stand");
}

int do_sit(string arg)
{
        mapping skl;
        object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg=="" ) return 0;

	if( me->query_temp("sitted"))
		return notify_fail("���Ѿ������ˣ�\n");

        skl = me->query_skills();
        sname  = keys(skl);

        if( arg == "lianzuo"){
	message_vision("$N̤����������ס����涫������\n", me);
        me->set_temp("sitted", 1);

/*        for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 100)
                me->unconcious();
        }
*/
	if ( me->query_skill("lamaism", 1) < 150){
                me->unconcious();
        }
	else if ( present("longxiang jing", me) && me->query("potential") > 0){
                message_vision(HIY"��ľ������ȼ��$N�����������������֪���Ȼ�԰�������������������͡�\n"NOR, me);
                me->start_busy(10+random(10));
                me->improve_skill("longxiang-banruo", me->query_int()*7/10
                * me->query("potential"));
		me->set("jing", 0);
                me->set("potential", 0);
                tell_object(me, "�����������������ˡ�\n");
		return 1;
        }
	return 1;
	}
}
int do_stand()
{
	if (this_player()->query_busy())
		return notify_fail("�㻹����վ������\n");

        message_vision("$Nվ������������������\n", this_player());
        this_player()->delete_temp("sitted");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("sitted"))
	return notify_fail("�����ߣ�\n");
	return ::valid_leave(me, dir);
}

// Code of ShenZhou
// Summer 9/25/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ƿ��¥");
        set("long", @LONG
�����Ƿ������޹���������һ�����ź�ɫ����������̴ľ�󴲣��ı�
ȫ�Ƕ����˷𾭵���ܡ�
LONG
        );
        set("exits", ([
                "down" : __DIR__"angqian",
        ]));
	set("objects", ([
		"/kungfu/class/xueshan/jiumo" : 1,
	]));

	replace_program(ROOM);
	set("cost", 1);
        setup();
}
/*void init()
{
        object me = this_player();

	if (me->query_skill("xiaowuxiang", 1) >= 20
	&& me->query_skill("longxiang-banruo", 1) >=60
	&& me->query("family/master_id") == "jiumozhi" ){
                tell_object(me, "\n\n" +
        "�Ħ�ǲ�̽��һ������书��ͻȻ˵����ͽ������չ��Ȼ����������\n" +
        "ָ��ָ���㡣�������ڵĻ��浶������ص���С�������Ϊ����Ȼ\n" +
	"��������������һ�����ף�����û�б�Ҫ�ټ��������������Ը�⣬\n" +
	"�ҿ��԰���������ɵ��������������С���๦��\n" +
        "���Ը�⣬���롰yes����\n\n");
	add_action("do_yes", "yes");
	}
}
int do_yes()
{
        mapping learned;

        object me = this_player();
        learned = me->query_learned();

        me->set_skill("xiaowuxiang", me->query_skill("longxiang-banruo", 1));
        me->improve_skill("xiaowuxiang", learned["longxiang-banruo"]);
	if( me->query_skill("xiaowuxiang", 1) > 1)  me->map_skill("force", "xiaowuxiang");
        me->map_skill("longxiang-banruo");
        me->delete_skill("longxiang-banruo");

        tell_object(me, HIY "\n�Ħ�������������������С�������죬������������������Ŵ�Ѩ��\n" +
		            "����ע�������������������ĸ��������𽥴�ͨ�ˣ����С��������ˣ�\n\n" NOR);

        return 1;
}
*/

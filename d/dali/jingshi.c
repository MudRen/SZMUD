// Code of ShenZhou
inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
�����ǻ�ü��ʦ���޵ĵط�������ֻ��һ�Ŵ���ʯ(stone)��
LONG
        );

        set("objects",([
                "/d/dali/npc/yellow" : 1
        ]));

     set("item_desc", ([
	"stone" : "һ��Բ����С����ʯ�������ݺύ������ʮ����ֱ�ߡ�\n",
        ]));

        set("cost", 1);
	 setup();
}

void init()
{
        add_action("do_draw", "draw");
}
int do_draw(string arg)
{
object me = this_player();

        if ( !arg || arg != "line" )
             return notify_fail( "ʲô��\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ʲô��\n");

if ((int)me->query_skill("finger",1) <= 40 ) {
             me->improve_skill("finger", me->query("str")+random(10));
             write( "�������ָ������ʯ���ϻ�����ȥ��\n");
          
me->add("jingli", -35);
}
else {
write( "�������ָ������ʯ���ϻ�����ȥ��ȴ�����Լ����Ծ����ú�ֱ��\n");
}
return 1;
}














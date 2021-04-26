// Code of ShenZhou
// path1.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��ɽ����");
	set("long", @LONG
�����ǻ�ɽ���£�����������С�������µ�һɽ����������ɽ����
ɽ����Զ������һ��������������������ʱ���������롸����ͨ������
���и�С��ׯ�������м��䷿�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hsstreet4",
  "north" : __DIR__"yuquan",
  "southeast" : __DIR__"shaluo",
]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

	set("cost", 2);
        setup();
}
 
static string current_id = "";
static int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void init() {
    object challenger, me = this_player();

    if ( (me->query("family/family_name") == "ѩɽ��" ||
          me->query("family/family_name") == "Ѫ����")
         && (me->query("combat_exp") > 100000) ) {
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1;
    }
}

int introduce_robber(object current_player)
{
    object robber;

    if ( objectp(present(current_player->query("id"), this_object())) )
    {
        robber = new(__DIR__"npc/robber");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());
        message_vision(HIC"һ��$N����ææ���˹�����\n"NOR, robber);
        message_vision(HIR"$N˵�������ǲ������¸ղ�׷���������ˣ�����Ҳ����ʲô�ö��������ǵĻ�����߿���\n" NOR, robber, current_player);
        robber->start_checking(current_player);
    }
    else
    {
        reset_to_normal();
    }
}

int reset_to_normal()
{

   current_job = 0;
   return 1;
}


// Code of ShenZhou
// Room: /d/xingxiu/xxroad3.c

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ�����������(sky)Ʈ�ż��䵭����
���ơ�һȺ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�������ɽ�³��ǵĲ�ԫ��
����ϡ�ɱ档·����һ������֮�Ͽ����״�(poem)������ɽ�������ǳǣ���
��ɽ����һ��С��ׯ��
LONG
        );
        set("exits", ([
  		"northdown" : "/d/qilian/yongdeng",
  		"eastdown" : "/d/village/wexit",
	]));

        set("item_desc", ([ 
"poem" : "�±��Ͽ���һ����ƽ�֣�

  ��  ��  ��  ��  ��  ��  ��  ��
  ʱ  ��  ��  ��  ָ  ��  ��  ��
  ��  ��  ��  ɽ  ��  ��  ��  ��
  ��  ӧ  ��  ��  ��  ��  ��  ��
  ��  ��  ��  ��  ��  ��  ��  
  ��  ��  ��  ��  ��  ��  
                      ��

�������Ǻú��ˣ�
\n",
"sky" : "
                              \\/             \\/
                   /*=*         \\/       \\/
                   (*=*=)         \\/  \\/
               {/*=**=/            \\/
                         __
                        /\\.\\_   
               /\\  /\\  /  ...\\   /\\
              / .\\/ .\\/    .. \\_/ .\\
             /  ..\\  /    ... . \\  .\\      /\\
            /͹͹͹\\/͹͹͹. ..͹\\͹.\\    / .\\  
  _͹͹͹͹/     ..͹     ͹͹͹..\\__.\\͹/  ..\\_͹͹͹͹͹͹͹͹͹͹͹͹_\n\n"
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 3);
        setup();
}
void init()
{
        object ob, robber, *inv, me=this_player();
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("value") >= 10000
                && !inv[i]->query("money_id")) j++;
        }
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player())
        && me->query_temp("rob_victim") && random(5)==1) {

                message_vision(HIR"ͻȻһ���������ߵ��������˳�������ס��$N��\n"NOR, me);
	        robber = new("/d/xixia/npc/mazei");
                robber->move(environment(ob));
        }
}	
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("ma zei", environment(me) ))
                return notify_fail("�����װͰ͵ؽе����Ŵ����㣬�콫������������ \n");
	else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}

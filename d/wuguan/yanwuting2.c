#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "���䳡");
       set("long", @LONG
��������ݵ����䳡���ǽ�ͷ��ƽʱ���˵����ǳɼ��ĵط���Ҳ��
�����ǻ����д衢�̵ֽĵط�����Χ����Щʯ��(suo)��ʯ��(gu)������
�����Ź�����֮�ΰڷ���÷��׮(zhuang)�������������˵������Ṧ�õġ�
LONG);
       set("exits", ([
             "east" : __DIR__"yanwuting1",
             "west" : __DIR__"yanwuting3",
             "north" : __DIR__"zhengting",
		]));
	set("objects", ([
	     __DIR__"npc/xuetu1" : 3,
             "/d/wuguan/npc/mu-ren" : 1,
		]));       
/*       set("item_desc", ([
             "zhuang" : "÷��׮�ǰ��Ź�����֮�β��ɵġ�\n",
             "suo" : "ʯ���Ǹ���ݵ�������ϰ�����õġ���������ž�(ju)һ�¡�\n", 
             "gu" : "ʯ�ķǳ��أ��㿴���ǲ������ƶ�(tui)����\n",]));*/
       set("outdoors", "wuguan");
       setup();
}
/*void init()
{
       add_action("do_ju", "ju");
       add_action("do_tui", "tui");
}
int do_ju(string arg)
{
       object ob = this_object();
       object me = this_player();
       if ( arg != "suo" )
        {write("���ʲô��\n");return 1;}
       if ( arg = "suo" )
        { if ( me->query_skill("hand") < 10 )
            return notify_fail(HIR"����������˫�ַ���ȥ��ʯ������ʯ�������˸��Ƶģ���˿������\n"NOR);              
          if(me->is_busy())
             return notify_fail("��������æ�š�\n"); 
      
          write(HIY"$n��һ���������ַ�����ʯ���߸߾ٹ�ͷ����\n"NOR);
          me->add("jingli", -20);
          me->improve_skill("hand", 20+random(20));
          me->start_busy(1+random(4));
          return 1;
           } 
} 

int do_tui(string arg)
{
       object ob = this_object();
       object me = this_player();
       if (arg != "gu")
         {write("����ʲô��\n");return 1;}
       if (arg = "gu")
         { if (me->query_skill("strike") < 10)
              return notify_fail(HIR"�������˳��̵���Ҳ�Ʋ�����ʯ�ġ�\n"NOR);              if(me->is_busy())
              return notify_fail("��������æ�š�\n"); 
           write(HIY"$n���۵��˫�ư�סʯ�ı�Ե��������ʯ���ƿ���һ�ߡ�\n"NOR);
     me->add("jingli", -20);
     me->improve_skill("strike", 20+random(20));
     me->start_busy(1+random(4));     return 1;
          }
}*/








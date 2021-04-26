#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_climb(string arg);
int do_exercise(string arg);
int do_practice(string arg);
int do_study(string arg);
int do_search(string search);
void create()
{
       set("short","����");
       set("long",@LONG
���������ϣ�������ݺ�ɽ�����֣�����һƬ�þ�ɫ��̧ͷ��ȥ��
������Ǻܶ��ˣ�����Ṧ��Щ���ܼ��������� (climb)�����¶�
���ż��겻֪���Ļ���(drug)��
LONG);

       set("item_desc", (["drug" : "�±ھ�Ȼ���ż��껨�ݣ����û������ô����滨��ݡ�\n"
]));       
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
       add_action("do_search", "search"); 
       add_action("do_exercise",  "exercise");
       add_action("do_exercise",  "dazuo");
       add_action("do_exercise",  "respirate");
       add_action("do_exercise",  "tuna");
       add_action("do_practice",  "practice");
       add_action("do_practice",  "lian");
       add_action("do_study",  "study");
       add_action("do_study",  "du");
}

int do_climb(string arg)

{ 
       object me = this_player();
       int gain,cost;
       if(me->is_busy())
           return notify_fail("��������æ�š�\n"); 
       cost = ( 200-me->query_dex()*me->query_skill("dodge")/20 )/20;
       if ( cost<10 )cost = 10;
       me->add("jingli",-cost);
       if( arg != "up" && arg != "down" )
                return notify_fail("������������\n");
	if(me->query_skill("dodge") < 10 && arg == "up" )
		return notify_fail("���Ṧ��������ôҲ������ȥ��\n");                   
    
       gain = me->query("con")*3/2;
        if(arg == "up" )
           {
          message_vision( HIY"\n$NС�������������ȥ��\n"NOR, me);
          me->move(__DIR__"cliff3");
          message_vision( HIY"\n$N����������\n"NOR, me);
          me->improve_skill( "dodge",gain+random( gain ) * 3/2);
          me->add("jingli",-cost);
          me->startbusy( 1 );
          return 1;
}
       else if(arg == "down" )
      {
       message_vision( HIY"\n$NС�������������ȥ��\n"NOR, me);
       message_vision( HIY"\n$N����������\n"NOR, me);
       me->move(__DIR__"cliff1");
       me->improve_skill( "dodge",gain+random( gain ) * 2/3);
       me->add("jingli",-cost);
       me->startbusy( 1 );
       return 1;
      }   
       return notify_fail("����������\n");
}
int do_exercise(string arg)
{
                 object me = this_player();
                 tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
                 return 1;

}
int do_practice(string arg)
{
                  object me = this_player();
                  tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ�������������\n");
                  return 1;
}
int do_study(string arg)
{
                 object me = this_player();
                 tell_object(me, "�����������ϣ��ֽŲ��ã������ó����������ڳ��������鰡��\n");
                  return 1;
}







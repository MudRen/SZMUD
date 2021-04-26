#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
void create()
{
       set("short","��ɽ����");
       set("long",@LONG
λ����ݺ�ɽ���һ���Ƚ϶����ͱڣ����ͱ�����һЩͻ���ƺ�
����������(climb)�����ͱڵĲ�Զ����һ������(board)��
LONG);
       set("exits",([
       		"east" : __DIR__"xiaojing2",
                   ]));
       set("item_desc",([
               "board" : "����д��"+HIC+"�˴�Σ�գ���ע��"+NOR+"��\n",
                 ]));   
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
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
       gain = me->query("con")*3/2;
       if( arg == "up" )
      {
          message_vision( HIY"\n$NС�������������ȥ��\n"NOR, me);
          me->move(__DIR__"cliff2");
          message_vision( HIY"\n$N����������\n"NOR, me);
          me->start_busy( 0 );
          me->improve_skill( "dodge",gain+random( gain ));
          me->add("jingli",-cost);
          return 1;
      }     
        return notify_fail("����������\n"); 
}










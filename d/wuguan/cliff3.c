#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
int do_search(string arg);void create()
{
       set("short","�¶�");
       set("long",@LONG
�����Ѿ����¶���������һ��ƽ̨������ֻ����һЩ����(drug)����
������ȥ�������ȫչ����������
LONG);
       set("item_desc",([
                "drug" : "�����кܶ��ҩ�ݡ�\n"]));
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
       add_action("do_search", "search");
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
       gain = me->query("con")*2;
       if( arg == "down" )
      {
          message_vision( HIY"\n$NС�������������ȥ��\n"NOR, me);
          me->move(__DIR__"cliff2");
          message_vision( HIY"\n$N����������\n"NOR, me);
          me->start_busy( 0 );
          me->improve_skill( "dodge",gain+random( gain )*3/2);
          me->add("jingli",-cost);
          return 1;
      }     
        return notify_fail("���ﲻ����������\n"); 
        return 0;
}

int do_search(string arg)
{
              object me = this_player();
              int gain,cost,rr,aa,bb;
              if(me->is_busy())
              return notify_fail("��������æ�š�\n"); 
              cost = ( 40-me->query_dex())/2;
              if ( cost<10 )cost = 10;
              me->add("jingli",-cost);
              gain = me->query("con")*2;
              aa = gain + random(20);
              bb = gain + random(10);
              rr = gain + random(10);
              if (arg == "drug")
               {
                me->start_busy(random(5));
                 if ( random(rr) > 32)
                  { 
                   message_vision(HIR"$N��ǰһ�����ҵ�һ���ҩ��\n"NOR, me);
                   me->add("combat_exp",aa);
                   me->add("potential",bb);
if ( me->query("potential") > me->query("max_potential"))
{me->set("potential", me->query("max_potential"));}
                 
                tell_object(me,HIC"��õ���"+HIG+chinese_number(aa)+NOR+HIC+"��"+HIR+"����\n"NOR);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(bb)+NOR+HIC+"��"+HIW+"Ǳ��\n"NOR);
                          return 1;}  
                   else 
                      {
return notify_fail(HIR"$N�ҵ��˼��ò�ҩ��������ûʲô�á������ְ����ӵ��ˡ�\n"NOR, me);
        }
           return 1;
}
     return;
}              









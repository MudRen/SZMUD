// by remove /16/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
����������ղظ��Ÿ����书�ܼ��ĵط���
LONG);
        set("exits", ([              
             "north" : __DIR__"guangchang"]));
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_hit", 1);
        set("cost", 1);
        setup();
 
//replace_program(ROOM);
}void init()
{
        object *inv, me = this_player();
        int i, j=0;
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
           if((string)inv[i]->me_query("id")=="book") j++;
           }
           me->set_temp("getbooks", j);
}
int valid_leave(object me,string dir)
{
        object *inv;
        int i, j=0;
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
          if((string)inv[i]->me_query("id")=="book") j++;
           }
         if ( j == (int)me->query_temp("getbooks")+1 )                me->set_temp("wuguan/�ܼ�", 1);
         if ( j == (int)me->query_temp("getbooks")+1 )
      return notify_fail("�㲻����ô���ģ�һ��������ô���顣\n");
         return ::valid_leave(me, dir);

}



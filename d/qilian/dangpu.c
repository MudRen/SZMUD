//�㳡 by remove 15/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short", "���浱��");
     set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š����浱�̡�
�ĸ����ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨(desk)��ĥ�Ĺ�����ˡ�
��̨������������ӣ��ֱ�����Ÿ�ʽ����(weapon)�����ߴ���(armor)��
ҩ��(drug)���鼮(book)����������ʽ����(misc)����̨����ϳ���ͷ
Ҳ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�����ӣ�����á�������Ը��
�Ų���Ƿ����
LONG);
     set("no_clean_up", 0);
     set("no_beg", 1);     
     set("exits", ([  /* sizeof() == 2 */
           "west" :  __DIR__"lanzhou",]));
     set("objects", ([
                __DIR__"npc/chaofeng" : 1,]));
     
     setup();
    replace_program(ROOM);
}
 /* 
   void init()
{
     add_action("do_knock", "knock");
}
int do_knock(string arg)
{
     object me;
     me = this_player();
     if ( arg == "desk" )
     {  message_vision("$N�����ڹ�̨����ۼ��£��ֶ��ϳ�������˵�˼��䡣�ϳ�������˸����Ƶģ�����������$N����˺��á�\n",me); 
     me->move(__DIR__"houtang");
     me->start_busy( 0 );return 1;}
     return notify_fail("��Ҫ��ʲô��\n");              
}
*/






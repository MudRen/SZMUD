// Code of ShenZhou
// ��ɽ��
// qfy 26/6/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_strike(string);

void create()
{
        set("short", "��");
	set("long", @LONG
���߷���һ�����ã��������ϵ������Ѹ����Ϊ���������Է�����
���󸫡��ּ�ʯ���϶�������������һƬƬ�кۣ�ԭ�������׵���������
����ǰ�������������ģ���Զ�������������ã�һ���бڶ�����һ�����
һ�š�����������ӹ�ȥ��	
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
	"left" :  __DIR__"midong",
	]));
	   
	set("cost", 1);
                setup();
}

void init()
{
	add_action("do_strike","strike");
}

int do_strike(string arg)
{
   int n, q;
   object weapon, me = this_player();
   n = me->query("neili");
   q = me->query("qi");
   
   if( !arg || arg!="wall" ) 
       return notify_fail("��Ҫ������ô����\n");
                      
   if(!objectp(weapon = me->query_temp("weapon"))
   || (string)weapon->query("skill_type") != "sword"){
               
	message_vision(
	"$Nվ���������ݳ��������ʽ������һ������˫��ͬʱ����ʯ�ڡ�\n", me);
	message_vision(
	"���ʲôҲû�����������Ʊڵķ��������ԣ�$N�Լ��������ˡ�\n", me);
	me->set("neili",n-200);
	me->receive_damage("qi",200,"����͸֧��������");
   }
   else {
   	if (n>=200) {
   	   message_vision(
   	   "$N�ٽ�������������ʯ�ڣ�����һ��������������ʯ��֮�У�ֱû������\n",me);
   	   message_vision(
   	   "$N�漴�������������������֮��������ʯͷ��ס���䣬¶�����ڡ�\n", me);
   	   set("exits/out", __DIR__"shandong");
   	   me->set("neili",n-200);
   	   remove_call_out("close");
   	   call_out("close", 5, this_object());
   	 }
   	 else {
   	   message_vision(
   	   "$N�ٽ���������������ʯ�ڣ��ϵ�һ��������������ˣ�ԭ���������㣡\n", me);
   	   me->set("neili",0);
   	   me->receive_damage("qi",200,"����͸֧��������");
   	   destruct(weapon);
   	 }
   	 
   	 return 1;
   	         
    }
    
    return 1;
    
}         	     	         	     	    
  
void close(object room)
{
    message("vision","ʯͷϡ�ﻩ��̮���������ַ�ס����ڡ�\n", room);
    room->delete("exits/out");
}

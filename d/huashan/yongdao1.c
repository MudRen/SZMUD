// Code of ShenZhou
// ��ɽ��
// qfy 26/6/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_use(string);
int do_strike(string);
int do_left();

void create()
{
        set("short", "��");
	set("long", @LONG
����һ���������������ôҲ����������֪ͨ���δ����к�Σ�ա�	
LONG
        );
	 switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
        default:
                set("objects", ([ "/d/xingxiu/npc/spider2" : 1]));
                break;
        }

	set("cost", 1);
        setup();
}

void init()
{
	write("ֻ�������ʯͷϡ�ﻩ��̮����������ס����ڡ�\n");
	add_action("do_strike","strike");
	add_action("do_use","use");
	add_action("do_left","left");
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
	"���ʲôҲû�����������Ʊڵķ��������ԣ�$N�Լ���������\n", me);
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
  
int do_use(string arg)
{
    object me = this_player();
       
    if( !arg || arg=="" ) return 0;
    if (!present("fire", me))  return 0;
    if( arg=="fire" ) {
         write("���ȼ�˻��ۣ��㷢�����߷���һ�����ã������ų���һ���亹��\n");
         write("�������ϵ������Ѹ����Ϊ���������Է��������󸫡��ּ�ʯ���϶�\n");
         write("������������һƬƬ�кۣ�ԭ�������׵�������������ǰ����������\n");
         write("���ģ���Զ�������������ã�һ���бڶ�����һ�����һ�š�����\n");
         write("������ӹ�ȥ������Ψһ�ĳ����� left��\n");
         this_player()->set_temp("marks/��", 1);	
                  } 
 
     return 1;
}

int do_left()
{
    object me = this_player();
    
    if ( me->query_temp("marks/��") ) {
         message("vision", me->name() + "ͻȻ�����ˡ�\n", environment(me), ({me}) );
         me->move(__DIR__"midong");
	 message("vision", me->name() + "���˹�����\n", environment(me), ({me}) );
         me->delete_temp("marks/��");
    }
    else {
         write("ʲô��\n");
    }
    
    return 1;
}         
                		

void close(object room)
{
    message("vision","ʯͷϡ�ﻩ��̮���������ַ�ס����ڡ�\n", room);
    room->delete("exits/out");
}
                    

// Code of ShenZhou
// ��ɽɽ��
// qfy 26/6/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_mianbi();
int do_strike(string);

void create()
{
   set("short", "ɽ��");
   set("long", @LONG
ɽ�����п������Ĵ�ʯ����֪�����ж��ٻ�ɽ�ɵ�ǰ���ڴ�˼����
�ڣ���������ʯ�������û��ʯ��(wall)�����š������������
�֣������������̣��ʻ��Ծ������а�硣�����̵ֿþ����Ƿ��������
���书һ��ʮ���˵á�
LONG
	);
   set("exits", ([ /* sizeof() == 1 */
   "out" : __DIR__"siguoya",
   ]));

   set("item_desc", ([
      "wall" : "һ��ܺ��ʯ�ڡ�\n",
   ]));
       
	set("cost", 2);
   setup();
}

void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("huashan/job_pending") ) {
	me->set_temp("hz_job/sgy", 1);
   }

   add_action("do_mianbi","���");
   add_action("do_mianbi","mianbi");
   add_action("do_strike","strike");
   add_action("do_lingwu","lingwu");
}

int do_mianbi()
{
   int shen_n, check, level;
   object me = this_player();
   shen_n = me->query("shen");

   level = (int)me->query_skill("force",1);
   check = level*level*level;

   write("���ڴ�ʯ�����������������ʯ��������˼��\n");

   if ( random(15) == 9 && !me->query_temp("marks/��") ) { 
      write("���ã���ͻȻ��һ���Ʊ�(strike)�ĳ嶯��\n");
      me->set_temp("marks/��", 1);
      }
      me->set_busy(10);

   if ( random(200) == 18 && (int)me->query("shen") < 100000 ) {
      me->set("shen",shen_n+100);
      write("����������������ˡ�\n");
      }

   if ( random(200) == 1 && (int)me->query_skill("force", 1) <= 40 
   && check < (int)me->query("combat_exp")*10 ) {
      me->receive_damage("jing", 10, "�����ʴ�����");
      me->improve_skill("force", me->query("int"));
      write("���������ڹ�����ļ������ѡ�\n");
      }

   return 1;
}        
		
int do_lingwu()                
{
   object me = this_player();
   int level, check;

   level = (int)me->query_skill("zixia-gong",1);
   check = level*level*level;   
   
   if ( (int)me->query_skill("zixia-gong", 1) >= 50 
   && (int)me->query_skill("zixia-gong", 1) <= 100
   && present("zixia book", me) && (int)me->query("jing") > 29 ) {
      if ( check < (int)me->query("combat_exp")*10 ) {
	me->receive_damage("jing", 20, "�����ʴ�����");
	me->improve_skill("zixia-gong", me->query("int"));
	write("����������ϼ�񹦷���ļ������ѡ�\n"); 
      }
      else {
	write("��ʵս���鲻�㣬�޷�������ϼ�񹦡�\n");
      } 
   }    
   else if ( (int)me->query("jing") < 30 ) {
      write("�㾫���޷����С�\n");
   }            
   else {
     write("ʲô��\n");
   } 
	 
   return 1;
}    

int do_strike(string arg)
{
   int n, q;
   object weapon, me = this_player(); 
   n = me->query("neili");
   q = me->query("qi");
	
 if( me->query_temp("marks/��") ) 
 {
   
   if( !arg || arg!="wall" ) 
       return notify_fail("��Ҫ������ô����\n");
				
   if( !objectp(weapon = me->query_temp("weapon"))
   || (string)weapon->query("skill_type") != "sword" ) {

   if( me->query("neili") < 200)
	return notify_fail("�������������\n");

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
	   "$N�ٽ�������������ʯ�ڣ�����һ��������������ʯ��֮�У�ֱû������\n", me);
	   message_vision(
	   "$N�漴�������������������֮��������ʯͷ��ס���䣬¶��һ��խխ�Ŀ׵���\n", me);
	   set("exits/enter", __DIR__"yongdao1");
	   me->set("neili",n-200);
	   me->delete_temp("marks/��");
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
 else {
   write("ʲô��\n");
 }     
   
 return 1;    
}

void close(object room)
{
    message("vision","ʯͷϡ�ﻩ��̮���������ַ�ס����ڡ�\n", room);
    room->delete("exits/enter");
}

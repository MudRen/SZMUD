// Code of ShenZhou
// ��ɽ�ض�
// qfy 26/6/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;
string do_look();
int do_lingwu();
int do_ketou(string);

void create()
{
   set("short", "�ض�");
   set("long", @LONG
��ǰ������һ�������ʯ���������ݵ���ǧ��֮�ڣ��������߾ߺ���   
���������ԣ����Ծ��б��У�һ�����ƣ�һ���йٱʣ�һ��������һ��ͭ
����һ���������𵲣���һ���������������������е�������һ��������
���ǵ����ƽ��ǽ�������û�м�����ֻ������ɽ�������ɴ�ͻ��һ���ʯ
(stone)�����Ǹ�ƽ̨��
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
   "right" : __DIR__"yongdao2",
   ]));
              set("objects", ([ 
                      "/d/huashan/obj/changjian.c" : 1, 
              ])); 

   set("item_desc", ([
      "wall" : (:do_look :),
      "dazi" : 
	"���������ɣ��޳����������䲻ʤ�����㺦�ˡ���ÿ�ĸ���һ�ţ�ÿ��\n"
	"�ֶ��г������������ɽʯ�����ü������ı��п��룬������磬ʮ��\n"
	"����������䣬���н�������̬֮��\n",
      "xiaozi" :
	"�����Ը���������С�֣����ǡ����������������ɳ��Ѽ����������ܡ�\n"
	"����ų�ӡ����������ۣ����ھ������˵���䡣\n",
      "skeleton" :
	"�������ϵ������Ѹ����Ϊ��������֪�ڴ��ѳ�����ʮ�ꡣ\n",
      "stone" :
	"��ʯ֮��ʯ��(wall)�Ͽ�ʮ��������(dazi)������С��(xiaozi)����\n",
   ]));
   
   set("book_count",3);
           
	set("cost", 2);
   setup();
}

void init()
{
   this_player()->set_temp("ketou_times", 0);   
   add_action("do_lingwu","lingwu");
   add_action("do_ketou","ketou");
   add_action("do_ketou","kneel");
}

int do_lingwu()                
{
   object me = this_player();
   int check;

   if ( (int)me->query_skill("staff", 1) >= 30
   && (int)me->query_skill("staff", 1) <= 100
   && present("staff book", me) )
   {
     check = (int)me->query_skill("staff",1)*(int)me->query_skill("staff",1)*(int)me->query_skill("staff",1);
     if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") > 29 ) {
     	me->receive_damage("jing", 20, "�����ʴ�����");
      	me->improve_skill("staff", me->query("int"));
      	write("�������˻����ȷ�����ļ������ѡ�\n");
     }
     else if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") < 30 ) {
      	write("�㾫���޷����С�\n");
     }	
     else {
	write ("��ʵս���鲻�㣬�޷���������ȷ���\n");
     }	
   } 
   else if ( (int)me->query_skill("staff", 1) > 100 ) {
     write("������ȷ�������¯���࣬���ܴ�����ѧ��ʲô�ˡ�\n");
   }	  
   else {
     write("ʲô��\n");
   } 
         
   return 1;
}    

string do_look()
{
   object me = this_player();	
   int check;	
	
   if ( !present("sword book", me) || (int)me->query_skill("sword", 1) > 100 ) {
   switch (random(5)) {
   case 0:
   	write("�����ʯ�����տ�ʱ����һ���ֿ��ţ��������Ժ��ƺ�ɽ�����ڴˡ���\n");
	write("��һ��֮�����������Σ�ÿ��������һ�飬һ��ʹ������һ��ʹ����\n");
	write("����һ����˵Ҳ�������ٸ����Σ���Ȼ��ʹ�����������ƽ�ʹ������\n");
	write("�εĽ�����\n");
	break;
   case 1:
   	write("ʯ���Ϻ�Ȼ����һ���ּ������ų˷��ų��ƾ��ƻ�ɽ�����ڴˡ�����\n");
   	write("�����Զ���ͼ�Σ�ʹ��������ֻ�ݲ����ʣ�������Ϊ��ª����������\n");
   	write("֮�п������ף������ǻ�ɽ���������Ʒ������������ӯ�鶯����֮\n");
   	write("�Բ������г���һ��ֱ���εı��У���֪���ǰ�������ǹì���ۼ�ʹ\n");
   	write("�����εĹ�����������֮�������ǻ�ɽ�����Ŀ��ǡ�\n");
   	break;
   case 2:
	write("ֻ��ʯ��������ж���ͼ�Σ�ʹ������ʹ�Ľ��������Ѳ⣬Ʈ���쳣\n");
	write("�����Ǻ�ɽ�����ľ��С���ʹ�����ζԲ������ʹ����һ�����ƣ���\n");
	write("ʽ��죬����ȴ����֮�����������ʲ�������ҵ�����ɽ�����ĳ�\n");
	write("����ȫ�޷����ӡ�\n");
   	break;	
   case 3:
	write("ʯ�����ϽǵĶ���ͼ���п̵������ƽ�̩ɽ��������ʽ��̩ɽ������\n");
	write("Ѹ���������ƣ����������ѣ�һ�����������಻�����ƺ�����ֹͣ\n");
        write("���ƽ�̩ɽ����������ʹ���йٱʣ������������Կ��ƿ죬һ���ں�\n");
	write("�������ţ��˵��Ǿ��춯�صľ�ѧ��\n");
        break;
   case 4:
	write("ʯ���ұ߻��ж���ͼ�Σ�ʹ�����ν�������ɭ�ϣ������ݺᣬ������\n");
	write("����������ɽ�����ľ��С���һ�������õı������������е�������\n");
        write("��ɨ��ǰ������а���ɽ�����ƾ��ƾ��������޿���ȡ����ʹ����\n");
	write("Ψ���������Ͷ����\n");
        break;
   }
   }	
   else if ( (int)me->query_skill("sword", 1) >= 30
   && (int)me->query_skill("sword", 1) <= 100 )
   {
   switch (random(5)) {
   case 0:
        write("����ϸ�ع�Ħ��ɽ������\n");
	break;
   case 1:
	write("����ϸ�ع�Ħ̩ɽ������\n");	
	break;
   case 2:
	write("����ϸ�ع�Ħ��ɽ������\n");
        break;
   case 3:
	write("����ϸ�ع�Ħ��ɽ������\n");
        break;
   case 4:
        write("����ϸ�ع�Ħ��ɽ������\n");
        break;
   }
   check = (int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)*(int)me->query_skill("sword",1);	
   if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") > 29 ) {
      me->receive_damage("jing", 20, "�����ʴ�����");
      me->improve_skill("sword", me->query("int"));
      write("�������˻�����������ļ������ѡ�\n");
   }
   else if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") < 30 ) {
        write("�㾫���޷����С�\n");
   }
   else {
        write ("��ʵս���鲻�㣬�޷��������������\n");
   }

   }
	
   return "";
} 

int do_ketou(string arg)
{
   object book, *obs, me = this_player();
	
   if( !arg || arg!="skeleton" ) 
       return notify_fail("ʲô��\n");
   
   message_vision("$N�����������ڼ��ߺ���ǰ��������������һ����ͷ��\n", me);
   me->add_temp("ketou_times", 1);
	
   if( me->query_temp("ketou_times") == 20 && !me->query_temp("marks/��") ) {
   	write("\n��ͻȻ����������һ�ߺ��Ǻ���ʯ���Ͽ��м���С�֣�\n\n");
   	write("�������ո���������������ʦ���������ʦ������ʱȴδ�ܼ�ʱЧ\n");
   	write("����ʦ�Ų�����ѡ���̾��ͽ��Ϊͬ�š��غ�����ѩ��ޣ��ֿ�ʦ��\n");
   	write("�Ӵ�ʽ΢���������档Ψ������ɽ������������\n");
   	write("���ܲ���С�ڣ����ħ��ʮ���ϣ�ʵ����������Ҳ���������֣���\n");
   	write("ν��Ե���븰��ɽ�ᴦ������ᵱ�����Խ̣������񽣡�\n");
   	write("�ڻ�ɽ����������������������������������֮����\n\n");
   	write("\t\t\t\t\t��ɽ��ͽ ��������\n\n");
   	me->delete_temp("ketou_times");
   	me->set_temp("marks/��", 1);
   }

   if ( me->query_temp("ketou_times") == 15 ) {
	message_vision("\n������$N��ǰ��������������һ������������$Nһ����\n\n", me);
 	message("vision","��Ҳ������һ����\n\n", environment(me), ({me}));
   }
   
   if( me->query_temp("ketou_times") == 10 && !present("staff book",me) 
   && query("book_count") >= 1 && !me->query_temp("marks/��") ) { 	 
	message_vision("\nֻ��$N��ͷ�ĵ���ͻȻ������ȥ��¶��һ�������ε�С����\n", me);

	obs = filter_array(children(__DIR__"obj/staff_book.c"), (: clonep :));
        if (sizeof(obs) > 4)
	return notify_fail("�㷢��ԭ����������������������֪�����к���ͼ��\n");

	book = new("/d/huashan/obj/staff_book");
	add("book_count", -1);
	book->move(me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ���ȷ�ͼ�⡣", me->query("name")));
        message_vision("$N��С����һ���ų˷����µ��ȷ�ͼ�������պá�\n\n", me);
	me->set_temp("marks/��", 1);
   }	
   
   me->add("jing",-5, "�����ʴ�����");
   write("������е�����������������ڿ�ͷ��Ե�ʡ�\n");

   return 1;
}

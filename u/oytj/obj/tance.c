// glass.c
#include <ansi.h>
inherit EQUIP;
void create()
{
   set_name(HIB"ʵ��̽����" NOR, ({ "detector", "glass", "device" }) );
   set_weight(30000);
   set("unit", "��");
   set("long",
  HIB"����һ��ʮ�־��ܵĴ���ʵ��̽������������ͨ�����Ʊ��˵���������\n" "̽��(tan)���˵ĸ���ʵ����\n"NOR);
   set("value", 500);
   set("no_get",1);
   set("type", "misc");
   set("apply", ([
     "ͷ��":   0,
   ]) );
}
void init()
{
   add_action("do_detect", "tan");
}
int do_detect(string arg)
{
   object ob;
   int sen, sk;
   string skill;
   if( arg ) ob = present(arg, environment(this_player()));
   else ob = this_player()->query_opponent();
   if( !ob ) return notify_fail("��Ҫ̽��˭��\n");
   sen = (int)ob->query("sen");
   if( stringp(skill = ob->query("attack_skill")) )
     sk = ob->query_skill(skill);
   else
     sk = 0;
   ob->start_busy(5);
   message_vision("$N��Ȼӿ���Ī�������˯��,���˰���ſ�ʼ�����ָ�������\n",ob);
   
   printf("̽������ʾ%s�������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("age") );

 
printf("̽������ʾ%s�����ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("shen") );

 
printf("̽������ʾ%s�������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_str() );

 
printf("̽������ʾ%s�������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_int() );

 
printf("̽������ʾ%s�ĸ����ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_con() );

 
printf("̽������ʾ%s�����ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_dex() );

 
printf("̽������ʾ%s����ò�ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_per() );

 
printf("̽������ʾ%s�ĸ�Ե�ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("kar") );

 
printf("̽������ʾ%s��פ�����ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("beauty", 1) );

 
printf("̽������ʾ%s�Ķ���д���ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("literate", 1) );

 
printf("̽������ʾ%s�Ļ����ڹ��ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("force", 1) );

 
printf("̽������ʾ%s�Ļ����м��ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("parry", 1) );

 
printf("̽������ʾ%s�Ļ����Ṧ�ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_skill("dodge", 1) );

 
printf("̽������ʾ%s�������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("max_neili") );

 
printf("̽������ʾ%s�ļ����ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("jiali") );

 
printf("̽������ʾ%s�ĵ�ǰ���ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("qi") );

 
printf("̽������ʾ%s��������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("max_qi") );

 
printf("̽������ʾ%s��ս�������ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

 
printf("̽������ʾ%s�еĿ����붾�ǣ�%d\n",
     ob->query("name"), 
     (sk*sk*sk) * (100 + sen) / 100 + (int)ob->query_condition("kuihuazhen_poison") );
   return 1;

}


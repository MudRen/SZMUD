//code by cheap
//11-10-01
#include <ansi.h>
inherit NPC;
void create()
{
set_name("С��",({"xiao si"}));

set("title",HIC"����"NOR);
set("age",14);
set("gender","����");
set("long", "����һ��ʮ�����С����������С��������
ЩӪ�������� \n");
setup();
carry_object("/clone/armor/cloth")->wear();
}
void init()
{
object ob;
::init();
if(interactive(ob =this_player())&& !is_fighting() ) 
remove_call_out("greeting");
call_out("greeting",1,ob);
}
void greeting(object ob)
{
if(!ob || environment(ob) !=environment()) return;
switch(random(2)) 
{
case 0:
command("say ��Ҫ�����⳵ȥ�ڿ������\n");
break;
case 1:
command("say ��Ҫ�����⳵�Ϳ��ˣ�Ҫ�ǵ������Ϲ������㲻Ҫ���Ұ���\n");
break;
}
}


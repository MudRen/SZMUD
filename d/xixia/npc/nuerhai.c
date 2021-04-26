// Code of ShenZhou

#include <ansi.h>

inherit NPC;
int ask_me();
int ask_wage();
void create()
{
	set_name("Ŭ����", ({ "nuerhai"}) );
	set("title", "һƷ���ܹ�");
	set("gender", "����");
	set("age", 55);
	set("long",
		"���Ǹ����μ��ߡ����Ӽ���ĺ��ӡ�\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 600);
	set("eff_qi", 600);
	set("qi", 600);
	set("max_jing", 500);
	set("jing", 500);

	set_temp("apply/attack",  60);
	set_temp("apply/defense", 60);

	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	
	set("inquiry",
        ([
		"Ч��" : (: ask_me :),
		"��Ǯ" : (: ask_wage :),
	]));

	setup();

        carry_object("/d/city/obj/cloth")->wear();
}

int ask_wage()
{
	say("Ŭ����˵�������أ�\n");
	this_player()->set_temp("wait_ling", 1);
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;

	if (who->query_temp("wait_ling") 
	&& ob->query("id") == "qingtie ling" && ob->query("done")){
	obj=new("/clone/money/gold");
	obj->move(who);
	who->delete_temp("wait_ling");
	say("Ŭ�����ݸ��㼸���ƽ�˵�����������պá�\n");
	call_out("destroy_it", 1, ob);
	return 1;
	}
	else{ return 0;}
}
void destroy_it(object ob)
{
	if (ob)
	destruct(ob);
}
int check_worker()
{
	object *all;
        int i,j=0;

	all = users();

                for(i=0; i<sizeof(all); i++){
	if(all[i]->query_temp("xixia/һƷ��"))
        printf("%s(%s)\n", 
			all[i]->query("name"),
			all[i]->query("id"));}
}

int ask_me()
{
        object ob, me=this_player();
	object *all;
	int i,j=0;

	all = users();

	        for(i=0; i<sizeof(all); i++) 
        {
	 if(all[i]->query_temp("xixia/һƷ��") )
			j++;
	}
	if (j>4){
	say("Ŭ��������˵�������������ˣ������������ɣ�\n");
	return 1;
	}

        if (me->query("age") < 13 || me->query("combat_exp") < 15000)
	{
        command("say �����Сë�������ڴ�Ȥ�Ϸ�ɣ���������ȥ��");
	return 1;
	}

	if (me->query("shen") > -me->query("combat_exp")/2)
	{
	command("say ��Ī���ǰ׵��������������Ե׵İɡ�");
	return 1;
	}

	if (me->query_temp("xixia/testpass")) return 0;
	if (me->query_temp("xixia/һƷ��")) return 0;

if ((int)me->query_temp("marks/����1")) 
{
 say("Ŭ�����������õ�˵�����Ǹ��������𣬸�ʲô����������Һ��ţ�\n");
return 1;
}
else 
{
string qname = me->query("name");
me->set_temp("marks/����1", 2);
switch(random(3)) 
{
/*case 5:
me->set_temp("marks/����duan");
command("say ��ȥ�Ҷ��������������书�ɡ�");
break ;
*/
case 0: 
me->set_temp("marks/����ye", 2);
command("say ��ȥ��Ҷ��������书�ɡ�");
break ;  
case 1:
me->set_temp("marks/����nan", 2);
command("say ��ȥ���Ϻ��������������书�ɡ�");
break ;  
case 2:
me->set_temp("marks/����yun", 2);
command("say ��ȥ�����к����������书�ɡ�");
break ;
}
return 1;
}

}

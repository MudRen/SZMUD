// Code of ShenZhou
// /d/city/npc/shan.c
// xbc: 96/11/19

inherit NPC;
inherit F_VENDOR;

int do_look(string);
string ask_me();

void create()
{
        set_name("С�", ({ "shan", "xiao shan" }) );
        set("long", "�������ݳ�����ͤ�﹩Ӧ��ˮ��С橹��������һ�Զ��顣\n");
	set("title", "��Ů");
        set("gender", "Ů��");
        set("age", 16);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 18);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 10000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "�Ҿ���С橡�" ,
                "here" : "��������ͤ��������������д����ָ�ϵĻ������Ҷ���ģ�",
		"marriage" : "������˵�ˣ��������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"����" : "������˵�ˣ��������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"���" : "������˵�ˣ��������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"kiss" : "�����Ĳ����İ������ǻ��������������ߴ�ط��˰ɡ�",
		"sex" : (: ask_me :),
		"make love" : (: ask_me :),
		"love" : "�̣ϣ֣ţ����������˿��̶�������������" ,
		"����" : "���飿���������˿��̶�������������" ,
		"boyfriend" : "�����ѣ�����˵�ˣ���ǧ��Ҫ��˵��ϲ������" ,
		"������" : "�����ѣ�����˵�ˣ���ǧ��Ҫ��˵��ϲ������" ,
		"girlfriend" : "����˵�ˣ��뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"Ů����" : "����˵�ˣ��뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"wife" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"����" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"husband" : "�ұ����˵�ˣ��ɷ����һ�������ް���" ,
		"�ɷ�" : "�ұ����˵�ˣ��ɷ����һ�������ް���" ,
		"divorce" : "��˵�ˣ���飬����������Ŀ�ʼ�ˡ�" ,
		"���" : "��˵�ˣ���飬����������Ŀ�ʼ�ˡ�" ,
		"��ˮͰ" : "�ޣ���Ͱ�������ˮ�Ǹ����õģ����Լ�ȥ��ɡ�",
        ]) );

        setup();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("d/city/obj/flower_shoe")->wear();
        carry_object("u/qfy/obj/jiuzhuan");

/*
        set("vendor_goods", ({
                "u/xbc/obj/zhinan",
        }) );
*/
}

void init()
{
        object ob;

        ::init();
//        add_action("do_look","kiss");
      	add_action("do_look","kiss1");
       	add_action("do_look","kick");
      	add_action("do_look","slap");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");

//        add_action("do_buy", "buy");
//        add_action("do_list", "list");
        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

int ask_me()
{
        object me;
 
        me = this_player();
        switch( random(5) ) {
                case 0:
	                message("vision",
   "С���" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
                        command("slap " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 1:
		        message("vision",
   "С���" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
                case 4:
			command("xixi " + me->query("id"));
                        command("benger " + me->query("id"));
                        break;
        }
   	return 1;
}

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="shan" || target=="xiao shan") 
        if ((string)me->query("gender") != "Ů��") {
                   message("vision",
   "С���" + me->name() +"���������Ĳ�����ѽ��\n", me );

	switch( random(5) ) {
		case 0:
                        command("slap " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
                        break;
                case 1:
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("stare " + me->query("id"));
                        break;
                case 4:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
        }
	}
        return 1;

}

/*
void greeting(object ob)
{
	object zhn;

        if( !ob || environment(ob) != environment() ) return;

        switch( random(2) ) {
                case 0:
                say( "С橹�������һ�Զ��飬���������ˣ�̧��ͷ������һ�ۣ�ָ��ָǽ�ϵ�
���ܵ����ӵ������Լ����ɣ������Եľ��Ҹ���λ���ɡ�˵������ͷ����ȥ�ˡ�\n");
          	break;

                case 1:
                say( "С橹�������һ�Զ��飬���������ˣ������������˵����λ" + RANK_D->query_respect(ob) + "��
���������ȱ�ˮ���������ɣ������Ͽ������в�����ʾ�š�\n");
		break;
        }
        zhn = new("/u/xbc/obj/zhinan");
        zhn->move(ob);
        message_vision("С橸���$Nһ��С���ӡ�\n", ob);

	return;
}

*/

void kicking(object me)
{
        if (!me || environment(me) != environment())
                return;

        me->move("/d/city/dongdajie3");
         message("vision","ֻ�����ء���һ����������" +  me->query("name") +
                "������ͤ����˳���������һ������ӡ��ƨ������һ��СЬӡ��\n", environment(me), me);
}


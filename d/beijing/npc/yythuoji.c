// Code of ShenZhou
// /d/beijing/npc/yythuoji.c

#include <ansi.h>
#include <localtime.h>

inherit NPC;
inherit F_DEALER;

int do_look(string);
int env_cmp(object o1, object o2);

void create()
{
        set_name("һ���û��", ({ "huoji", "huo ji" }) );
		set_color(YEL);
        set("long", "����һ���õ�����ơ�\n");
        set("gender", "����");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 80000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
		set_skill("force", 30);
		set_skill("parry", 30);
		set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "�Ҿ���һ���û�ơ�" ,
                "here" : "���Ǿ���һ���á���������� exchange, �һ� ",
				"exchange" : "�һ����������� exchange xxx ��ʵ�֣�xxx ������Ӧ�Ľ�����",
				"�һ�" : "�һ����������� exchange xxx ��ʵ�֣�xxx ������Ӧ�Ľ�����",
        ]) );

        setup();
        carry_object("d/city/obj/cloth")->wear();
}

int init()
{
  object ob;
  ob = this_player();
  ::init();

  if( interactive(ob = this_player()) && !is_fighting() ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision(	"$N��$n΢΢Ц��Ц��\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        command( "say ��λ" + RANK_D->query_respect(ob)
                                + "����Ҫ�һ�����������Ҷ����ˡ�\n");
                        break;
                case 1:
                        command( "say ��λ" + RANK_D->query_respect(ob)
                                + "�������и��ּ�ֵ���Ƶ���Ʒ����������Ҫ�һ���һ����\n");
                        break;
        }
}

                   // Code of ShenZhou
// song.c ��Զ��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
int ask_zwz();

int auto_perform();

void create()
{
        set_name("��Զ��", ({ "song yuanqiao", "song" }));
        set("nickname", "�䵱����");
        set("long", 
                "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
                "ֻ������һ���ɸɾ����Ļ�ɫ���ۡ�����ȥ�������ʮ������΢�����ף�\n"
                "���糤�봹�أ�������⣬��������嵭��ͣ���ò�������ţ����ȴ����\n"
                "���֣��������귢����\n" );
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 42);
        set("int", 40);
        set("con", 42);
        set("dex", 40);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 1100000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("taiji-shengong", 220);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 220);
        set_skill("taiji-quan", 220);
        set_skill("strike", 180);
        set_skill("mian-zhang",180);
        set_skill("parry", 200);
        set_skill("sword", 160);
        set_skill("taiji-jian", 160);
        set_skill("literate", 101);
        set_skill("taoism", 200);
        //set_skill("taiji-gong",200);


        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");
        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�ؼ�" : (: ask_me :),
                                "�����߽���" : (: ask_zwz :),
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
        mapping fam;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
                return;
        }

        if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����䵱�������϶��µ㹦��");
                return;
        }

        if ((int)ob->query("shen") < 35000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�������������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        ob=new(__DIR__"force_book");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"Ū����һ��̫��ʮ��ʽ��");
        return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/2x") )
                {
                        command("say ������Ķ����ᣬ�һ����ܽ��㡣");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/1x") )
                {
                                command("say ���Ѿ���������Ҫѧ���顣");
                                return 1;
                }
        if ( me->query("combat_exp") < 100000 )
                {
                                command("say ���ʵս���黹���㣬������ò�Ҫѧ�������߽��󡹡�");
                return 1;
                }
        if ( me->query_skill("taiji-shengong", 1) < 100 )
                {
                                command("say ����ڹ�������������ѧ�������߽��󡹶���ٺ�����һ�棬�Ժ���˵�ɡ�");
                                return 1;
                }
        if ( me->query_skill("taoism", 1) < 100 )
                {
                                command("say ��Ե�ѧ�ķ��������˽⣬�����㲻����ᡸ�����߽��󡹵����⡣");
                                return 1;
                }
        if ( me->query("int") < 20 )
                {
                                command("say ������Բ����ߣ��������������߽��󡹵��������ڡ�");
                                return 1;
                }
        if ( me->query("max_neili") < 1000 )
                {
                                command("say ��������������ã���ȥ��û��������Ұɣ�");
                                return 1;
                }
        if ( me->query_skill("parry") < 100 )
                {
                                command("say �䵱�ľ�ѧ��������˸գ�����һ�㶫�����мܲ�ס����ôѧ�������߽��󡹣�");
                                return 1;
                }
                if ( me->query("jing") < 300 )
                {
                                command("say �����ڹ���ƣ�ͣ���ȥ��Ϣһ�°ɡ�");
                                return 1;
                }
        if ( me->query("jingli") < 2000 )
                {
                                command("say ��ϰ�������߽��󡹲���һ��������£��ҿ��������ڵ����������ʺ�����");
                                return 1;
                }
		if ( me->query("neili") < 2000)
		{
			command("say ��ϰ�������߽��󡹲���һ��������£������ڵ����������ʺ�����");
			return 1;
		}

                command("say �������ѧ��");
                write(HIY"��ѧ�Ļ���� xiang\n"NOR);
                me->set_temp("zhenwu/asking", 1);

                add_action("do_xiang", "xiang");
        
                return 1;

}

int do_xiang(string arg)
{
        object me = this_player();

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ�һ��λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say ���ȴ�����ھ���");
        message_vision(HIY"��Զ����������泯ǰ��������������ȭ�����ַ��ƣ����������������������ֺ͵����֣�һ���ϲ���\n"NOR, me);
        message_vision(HIY"��Զ���������ӣ��������ջص���\n"NOR, me);
        command("say �㿴������");

		message_vision(NOR"$N������ĥ����Զ�����ڵ���Ҫ����\n"NOR, me);

        call_out("steptwo",8,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(240);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 220)
        {
                message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
                me->set("zhenwu/1x", 1);
                return;
        }
}
#include "/kungfu/class/wudang/auto_perform.h"

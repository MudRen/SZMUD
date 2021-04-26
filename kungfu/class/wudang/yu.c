
                              // Code of ShenZhou
// yu.c ������


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_zwz();

void create()
{
        set_name("������", ({ "yu lianzhou", "yu" }));
        set("nickname", "�䵱����");
        set("long", 
                "������������Ķ����������ۡ�\n"
                "��������ʮ�꣬��Ŀ��࣬�������ء�\n"
                "�����䵱�����������ڶ�������ȴ�����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("shen", 80000);

                set("inquiry", ([
                                "�����߽���" : (: ask_zwz :),
        ]));

        set_skill("force", 120);
        set_skill("taiji-shengong", 110);
        set_skill("dodge", 130);
        set_skill("tiyunzong", 130);
        set_skill("cuff", 110);
        set_skill("taiji-quan", 110);
        set_skill("parry", 130);
        set_skill("sword", 130);
        set_skill("taiji-jian", 130);
//      set_skill("taoism", 80);
//      set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
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
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }

        if ((int)ob->query("shen") < 80000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say " + RANK_D->query_respect(ob) + "��������" +
                        "��������֮�£���һ�����㡣");
                return;
        }
        command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
                "�ұ����ˣ������������ɡ�");
        command("recruit " + ob->query("id"));
}

int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/3x") )
                {
                        command("say ������Ķ����ᣬ�һ����ܽ��㡣");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/2x") )
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

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ�����λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say ��Ҳ�ȴ�����ھ���");
        message_vision(HIG"������������������������̫���ĵ����෴��������������ȭ���������ơ���ʱ�䷿�������һ��������\n"NOR, me);
        message_vision(HIY"�������������ӣ��������ջص���\n"NOR, me);
        command("say �㿴������");

		message_vision(NOR"$N������ĥ�����������ڵ���Ҫ����\n"NOR, me);

        call_out("steptwo",10,me);
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
                me->set("zhenwu/2x", 1);
                return;
        }
}

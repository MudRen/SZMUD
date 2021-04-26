
// Code of ShenZhou
// xi.c ����Ϫ
// Update by Scatter
// V 1.0


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_zwz();

void create()
{
        set_name("����Ϫ", ({ "zhang songxi", "zhang" }));
        set("nickname", "�䵱����");
        set("long", 
                "��������������ĵ�������Ϫ��\n"
                "��������ʮ�꣬��Ķ�С����������Ӣ����\n"
                "Ϊ�˾����ܸɣ������Ƕ�ı���ơ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 36);
        set("int", 44);
        set("con", 37);
        set("dex", 36);

        set("max_qi", 3000);
        set("max_jing", 2600);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 110);
        set("combat_exp", 900000);
        set("score", 50000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 170);
        set_skill("tiyunzong", 170);
        set_skill("cuff", 160);
        set_skill("taiji-quan", 160);
        set_skill("strike", 170);
        set_skill("mian-zhang",170);
        set_skill("parry", 180);
        set_skill("sword", 190);
        set_skill("taiji-jian",190);
        set_skill("literate", 180);
        set_skill("taoism", 180);

                set("inquiry", ([
                                "�����߽���" : (: ask_zwz :),
        ]));
        //set_skill("taiji-gong",160);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");
        
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

        if ((int)ob->query_skill("wudang-jiuyang", 1) < 60) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����䵱�������϶��µ㹦��");
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

                if ( !me->query("zhenwu/5x") )
                {
                        command("say ������Ķ����ᣬ�һ����ܽ��㡣");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/4x") )
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

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ��ĸ�λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say ����Ҳ��ʵ�����������������");
        message_vision(HIM"����Ϫ�����еĽ��ڿ��л��˸���Ȧ���ֽ����������ȥ���ֽ��������ұߣ��������ᣬ��ת��һ��Ȧ��Ȧ��\n����������һ����û�뵽����Ȼ��ȫ�嵽���\n"NOR, me);
        message_vision(HIY"����Ϫ�������ӣ��������ջص���\n"NOR, me);
        command("say �㿴������");

		message_vision(NOR"$N������ĥ������Ϫ���ڵ���Ҫ����\n"NOR, me);

        call_out("steptwo",10,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(300);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 240)
        {
                message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
                me->set("zhenwu/4x", 1);
                return;
        }
}

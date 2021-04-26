// Code of ShenZhou
// /kungfu/class/wudang/yin.c ����ͤ
// xQin 14/08/99
// xQin 15/2/99
// xQin 04/01
// UPDATE BY SCATTER
// 1/9/2002

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me(object me);
int ask_zwz();

int auto_perform();

void create()
{
        set_name("����ͤ", ({ "yin liting", "yin" }));
        set("nickname", "�䵱����");
        set("long",
                "�����������������������ͤ��\n"
                "�����������ʮ���꣬���Ѿ�����糾֮ɫ������΢���߰ס�\n"
                "���䵱�����������������䵱������Ϊ��ͨ��\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 38);
        set("con", 36);
        set("dex", 38);

        set("max_qi", 2600);
        set("max_jing", 2200);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 100);
        set("combat_exp", 800000);
        set("shen", 80000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("cuff", 120);
        set_skill("taiji-quan", 120);
        //set_skill("chang-quan", 120);
        set_skill("strike", 120);
        set_skill("mian-zhang",120);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        //set_skill("wudang-jian", 200);
//      set_skill("throwing", 100);
        set_skill("literate", 180);
        set_skill("taoism", 180);
       // set_skill("taiji-gong",140);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");

        create_family("�䵱��", 2, "����");


       
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.shenmen") :),
        }) );

        set("inquiry", ([
                "���ͬ��" : (: ask_me :),
                "����ܽ" : "��������δ���ŵ����ӣ���Ȼ����������ͽ������",
                "����" : "����һ����Ҫ������ħ���������Լ���ܽ���졣����",
                "����ʮ����" : "����ʮ�����ˡ����� ����������ܽ��Ȼ����������ͽ������",
                                "�����߽���" : (: ask_zwz :),

        ]));

        
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
        command("sigh");
        command("say ��Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
                "�ұ����ˣ�������ܽȥ������������ͽ���������ҽ���"+
                "���Ҳ����Ե���Ҿʹ���һʽ�����ͬ�١���Ҳ����������"+
                "ʶһ����");

        ob->set("yinliting_teach",1);
}

string ask_me(object me)
{
        mapping fam; 
        me=this_player();
        
        if(me->query("family/family_name") != "�䵱��")
        {
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        }

        if(me->query_skill("taiji-shengong") < 60 )
        {
        command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
        return RANK_D->query_respect(me) + "�Ƿ�Ӧ����̫�����϶��µ㹦��";
        }

        if(me->query("shen") < 800000 )
        {
        command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
        return RANK_D->query_respect(me) + "��������" + "��������֮�£���һ�����㡣";
        }

        me->set("yinliting_teach", 1);
        command("sigh");
        return RANK_D->query_respect(me) + "Ҳ��" +
        "�ұ����ˣ�������ܽȥ������������ͽ���������ҽ���"+
        "���Ҳ����Ե���Ҿʹ���һʽ�����ͬ�١���Ҳ����������"+
        "ʶһ����";
        
}


int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/7x") )
                {
                        command("say ������Ķ����ᣬ�һ����ܽ��㡣");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/6x") )
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

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ����λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
        command("say ���ȴ�����ھ���");
        message_vision(HIC"����ͤ�����ϵĽ��ŵ���ǰ�������\n�컮һ�ŵ�������\n�ػ�һ�ŵð�����\n��һ�ŵ���ڤ��\n������һ�ŵó�Ϊ����֮��ͳ��\n����ͤ���еĽ�ͻȻ��ʼ��"NOR, me);
        message_vision(HIY"����ͤ�Ͻ��������ջء�\n"NOR, me);
        command("say �㿴������");

                message_vision(NOR"$N������ĥ������ͤ���ڵ���Ҫ����\n"NOR, me);

        call_out("steptwo",8,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(200);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 130)
        {
                                message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                                message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
                me->set("zhenwu/6x", 1);
                return;
        }
}
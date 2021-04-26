// Code of ShenZhou
//  /d/forest/npc/cl_mi.c  �׺�Ұ
//  by aln 2 / 98

#include <ansi.h>

inherit NPC;

string ask_job();
string ask_over();

void create()
{
        set_name("�׺�Ұ", ({ "mi hengye", "mi" }));
        set("title", "���ְﳤ��������");
        set("fam", "���ְ�");
        set("long",
"����һλ��ʮ��������ӣ��򹦸߶����γ��ְ�������������\n");
        set("gender", "����");
        set("age", 43);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 30);
        set("combat_exp", 180000);
        set("score", 8000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);

        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("cuixin-zhang", 100);
        set_skill("tangshi-jian", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("strike", "cuixin-zhang");
        map_skill("parry", "tangshi-jian");
        map_skill("sword", "tangshi-jian");

        prepare_skill("strike", "cuixin-zhang");

        set("inquiry", ([
                "���ְ�" : "���ְ������ڽ���һ��������ʢ��",
                "˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
                "����" : "��λ�����������ɰ������˼�˵���㡣",
                "����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
                "����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
                "������" : "�������ǳ��ְ�������֮һ����Ͻ���ⷽ��İ���",
                "�챦��" : "�챦�����ϰ��Ʋ��ˣ��ֽ����������ְ",
                "���ϰ�" : "��������ͷ���ˣ�������������ʮ���ӡ�",
//                "job" : (: ask_job :),
//                "over" : (: ask_over :),
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
}

string ask_job()
{
        object ling, me = this_player();
        string myfam;
        mapping job;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( me->query_temp("bangs/shoptime") )
                return RANK_D->query_rude(me) + "������úøɻ����ʲô��";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( !mapp(job = ling->query("job")) ) 
                return RANK_D->query_rude(me) + "��ȥ���ܹ��Ƕ�ѯ�ʰ���";

        if( job["type"] != "���" )
                return RANK_D->query_rude(me) + "��ô���Լ��İ��񶼸㲻�����";

        me->set_temp("bangs/shoptime", uptime());
        me->set_temp("apply/short",
   ({ HIR + myfam + "���"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        command("nod");
        return "������ⲻ�������ȱ���֡�";
}

string ask_over()
{
        object ling, me = this_player();
        string myfam;
        int shoptime, record;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( !(shoptime = (int)me->query_temp("bangs/shoptime")) )
                return RANK_D->query_rude(me) + "��û��ʼ�ɻ�����չ���";

        if( uptime() < shoptime + 60 )
                return RANK_D->query_rude(me) + "��ɻ��û���չ���";

        command("nod");
        me->delete_temp("bangs/shoptime");
        me->set_temp("apply/short", 
                ({ HIR + myfam + "����"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        record = 1 + random(10);
        me->add("combat_exp", record);
        log_file("BangJob", sprintf("%s��%sʱ������Ƶ�%s�����\n", me->query("name"), ctime(time()), chinese_number(record)));

        if( ling = present("bang ling", me) ) {
                ling->delete("job");
                ling->add("score", 1 + random(10));
        }

        return "�ɵò�����������ˡ�";
}

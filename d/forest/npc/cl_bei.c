// Code of ShenZhou
// /d/forest/npc/cl_bei.c ����ʯ
// by aln  2 / 98

#ifndef BANGS
#define BANGS  "/d/huanghe/"
#endif

#define BANGJOB    BANGS + "changle/bangjob"
#define BANGGOOD   BANGS + "changle/goods/"
#define BUSY_TIME 180
#define BIAOTOU    BANGS + "npc/biaotou"
#define BANGZHONG  BANGS + "npc/bangzhong"
#define BANGLING   BANGS + "obj/bangling"
#define BIAOHUO    BANGS + "obj/biaohuo"
#define CAILI      BANGS + "obj/caili"
#define XIANGFANG  "/d/forest/xiangfang"

inherit NPC;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/doc/info_store.h"
#include "/d/huanghe/doc/info_biao.h"
#include "/d/REGIONS.h"
#include "/d/huanghe/changle/info_guest.h"
#include "/d/huanghe/changle/info_business.h"

string ask_job();
string ask_cure();
string ask_salary();
string ask_dingdang();
int is_victim(object, string);

void create()
{
	set_name("����ʯ", ({ "bei haishi", "bei" }));
	set("nickname", "���ֳɴ�");
        set("fam", "���ְ�");
	set("long", 
		"����һ�������������ˣ�����ȥ��ɫ�԰ף�˵������������\n"
		"����ͣ�Ŀ����ţ��������ز�һ�㡣\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1900);
	set("max_jing", 500);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 40);
	set("combat_exp", 1200000);
	set("score", 8000);

	set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("cuff",  220);

	set_skill("ding-force",  200);
	set_skill("wuxingbu",   200);
	set_skill("wuxing-quan", 220);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff",  "wuxing-quan");
        map_skill("parry", "wuxing-quan");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "���ְ�" : "���ְ�ľ������������ܹܡ�",
                "���" : "��ȥ�ʰ����ɡ�",
                "����" : (: ask_job :),
                "job"   : (: ask_job :),
                "�书" : "�������˼ҵ��书����ǿ���ˣ��㻹�������ѧ�ɡ�",
                "����" : "��λ�����������ɰ������˼�˵���㡣",
                "˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
                "����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
                "����" : (: ask_cure :),
                "cure" : (: ask_cure :),
//                "���" : (: ask_salary :),
//                "salary" : (: ask_salary :),
                "��������" : (: ask_dingdang :),
                "����" : (: ask_dingdang :),
        ]));

	setup();

        carry_object("/clone/misc/cloth")->wear();
}

string ask_cure()
{
        object ling, me = this_player();
        string myfam;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";  

        if( time() < (int)me->query("bangs/curetime") + 60 )
                return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";
        
        if( (int)me->query("clbscore") < 10 )
                return RANK_D->query_rude(me) + "��Ϊ���г�������֪���̺ô���";

        if( (int)me->query("eff_qi") * 10 > (int)me->query("max_qi") * 8 )
                return "�˲��صĻ���������������ˡ�";

        command("nod");
       
        me->add("clbscore",-2);
        me->set("bangs/curetime", time());
        message_vision("$N��һһ����ҩ�ݸ�$n��\n", this_object(), me);
        message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n", me);
        me->receive_curing("qi", 50);
        return "��һ����ҩ��û���ˡ�";
}

string ask_salary()
{
        object wage, ling, me = this_player();
        string myfam;
        int amount;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( me->query_temp("bangs/pos") )
                return RANK_D->query_respect(me) + "����һ��֮���ˣ������Ƕ��������͡�";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( time() < (int)me->query("bangs/salarytime") + 1800 )
                return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";

        if( (amount = (int)ling->query("score")) < 30 )
                return RANK_D->query_rude(me) + "������ֺܲ�ѽ������Щ�����ڸ���";

        command("nod");
        me->set("bangs/salarytime", time());

        wage = new("/clone/money/silver");
        wage->set_amount(amount);
        ling->delete("score");
        me->add("clbscore",-amount);
        wage->move(me);
        message_vision("$Nת���ó�һ������ݸ�$n��\n", this_object(), me);
        return "��������ֲ�����ݺ������ȥ���ɡ�";
}

string ask_dingdang()
{	
	object ling, me = this_player();
        string myfam;
        int amount;
        
	myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";
                                
        if ((amount = me->query("clbscore")) < 1000)
        	return "�㲢Ϊ�Ա�������ʲô���ף�������»��ֲ����������ʡ�";
        
        if ( (!random(6)) || stringp(me->query("clbpos")) )
        {
        	command("say ��˵�����Ǹ�������̽������ʦֶ�Ĺ���ɡ�");
        	command("consider");
        	command("say �ðɡ�������Ա������ĵķ��ϣ�������һ�Ρ�");
        	message_vision("$N�漴����һ�����°�$n�����˳��ְ���᷿��\n",this_object(),me);
        	me->move(XIANGFANG);
        	me->add("clbscore",-1000);
        	tell_object(me,HIW"����ȥ��1000�㹦�͵��������\n"NOR);
        	return "��ȥ���ѽ��";
        }
        
        me->add("clbscore",-1000);
        tell_object(me,HIW"����ȥ��1000�㹦�͵������������ʧ���ˣ�\n"NOR);
        log_file("test/dingdang", sprintf("%s��%sʱ����������1000�㹦�͵㡣\n", me->query("name"), ctime(time())));
        return "Ī��������������⣬���ǲ�������Ϊ�á�";
}

#include "/d/huanghe/npc/guanjia.h";

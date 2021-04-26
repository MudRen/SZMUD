// Code of ShenZhou
// Kane
// maco
/*
shendiao 15
��һ�����书���ɣ�����ʦ����������Ѱ���ã��ڹ��µ����������½��˫������;��ʾ����ҹ����ˣ��㶼�������ֱ��ˡ�������϶���Ī���ᣬ����ͬ½��˫�����ɽ������®���ˡ�
�������������ǲ��� �����칤���ɣ��ü������������ϸ��ĵ���������������ȶ��ˣ�ʵ��Զʤ������� ����Ǭ����ˮ�������һ���������ƣ������Ե�����ϸ�緢��
*/
/*
����Ů��һ�Ű����Ϸ��˷��ˣ��˵������ϣ��������Է���������룬���Ǵ�����ȴ����ȫ�µģ���Ȼһ��֮΢������Ҳ������һ����˼���ǲ���Ҳֻƽ������˶���������С�㣬����⿵����������ɿڡ�
��������Ů��Ȼ���˼�ֻ���Ӹ��������ģ���������Ͷ�ɳ���̵��ǻ������⣬�˵�����ζ�ޱȣ����һ��ԣ�һ��Ȳɲ�����
*/

inherit NPC;
#include <ansi.h>
#include "/d/REGIONS.h";
//int auto_perform();
string ask_bagua();

void create()
{
        set_name("��Ӣ", ({ "cheng ying", "cheng", "ying" }));
        set("long",
"���ǻ�ҩʦ�����յ�С���ӣ�����ɫ��Ө��������ѩ���쵰������\n"
"��һ��СС���ѣ�΢�������Ǹ������Ĺ��\n");
        set("gender", "Ů��");	
        set("title", "�һ����ڶ�������");
	set("age", 19);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 1100);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 60);
	set("combat_exp", 90000);
/*
	set_temp("apply/armor", 50);
	set_temp("apply/attack", 80);
	set_temp("apply/dodge", 80);
*/
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("finger", 90);
	set_skill("parry", 90);
        set_skill("sword", 90);
	set_skill("qimen-dunjia", 90);
	set_skill("music", 90);
	set_skill("kick", 90);
	set_skill("bitao-xuangong", 90);
	set_skill("luoying-shenfa", 90);
	set_skill("tanzhi-shentong", 90);
	set_skill("xuanfeng-saoye", 90);
	set_skill("hand", 90);
	set_skill("lanhua-fuxue", 90);
	set_skill("strike", 90);
	set_skill("luoying-shenjian", 90);
	set_skill("yuxiao-jian", 90);
	
	map_skill("force", "bitao-xuangong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("finger", "tanzhi-shentong");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("strike", "luoying-shenjian");
	map_skill("sword", "yuxiao-jian");

	prepare_skill("strike", "luoying-shenjian");
	prepare_skill("kick", "xuanfeng-saoye");
/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/

	set("family",([
	"generation" : 2,
	"family_name" : "�һ���",
	"enter_time" : 999999999,
	"title" : "����",
	"master_name" : "��ҩʦ",
])) ;

//	create_family("�һ���", 2, "����");
        set("inquiry", ([
		"½��˫" : "�����ҵı��á�",
		"��Ī��" : "���Ǻ��������ɡ������Ůħͷ��",
		"��ҩʦ" : "СŮ��������ǳ�������΢������Ϊʦ����һ������ʵ�ǲ�����",
		"ռ��" : "���ɵ����ڶ����Ŷݼ������˽��ᣬ�����������Խ���ռ����",
		"���" : (: command(":(") :),
		"�һ���" : "��СŮ���������ĩѧ��ʵ����˵���һ������ӣ���������СŮ�����һ���ҲûԵ��̤��һ����",
		"������" : (: ask_bagua :),
		"bagua" : (: ask_bagua :),
        ]));

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/zhuxiao")->wield();
}

void init()
{
        ::init();
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
}


void attempt_apprentice(object ob)
{
        string tongmen,ttt;

	if (ob->query("gender") == "����") tongmen = "ʦ��";
	else  if (ob->query("gender") == "Ů��") tongmen = "ʦ��";


	if (ob->query("class") 
	&& (ob->query("class") != "beggar" && ob->query("class") != "officer") 
	|| (ob->query("family/family_name") != "�һ���" && ob->query("combat_exp") >= 10000) ) {
                command("say " + RANK_D->query_respect(ob) 
                + "��������ʿ���αؿ�СŮ�������Ц��\n");
                return;
        } 
	if( ob->query("family/family_name") != "�һ���"
	&& ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "��"
		+ob->query("family/family_name")+"���֣�СŮ�ӱ����΢���ɸ���Ϊ��ʦ��");
		return;
	}
	
	if (this_player()->query("gender") == "����") {
		command ("say " + RANK_D->query_respect(this_player()) + "���ڶ������������Լ���춼�ʦ��");
		return;
	}
	
	if( ob->query("family/family_name") == "�һ���"
        && ob->query("family/master_name") == "��ҩʦ" ) {
	        command ("smile");
                command ("say " + tongmen + "�����С�ÿ���Ц�᣿");
                return;
        }
	if( ob->query("family/family_name") == "�һ���"
        && ob->query("family/master_name") == "½�˷�" ) {
	if (this_player()->query("gender") == "����") ttt = "����";
	else  if (this_player()->query("gender") == "Ů��") ttt = "����"; 

	command("smile "+ ob->query("id"));
	command("say ��Ȼ����½ʦ�ֵĵ��ӣ���������Ҳ�����������ұ����΢������Ȳ���½ʦ�֡�");
	command("say �����գ�ƽ���㻹�Ǽ������ڹ���ׯ��"+ttt+"���ڱ���ѧ������ʲ�����ѣ��������Һ��ˡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", "����ׯ" + ttt);
	}
	else 
	command("say СŮ����������ʸ��أ�" + RANK_D->query_respect(ob) + "������Ͷ��ʦ�ĺá�");
}

int accept_kill(object me)
{
        if (me->query("family/family_name") == "�һ���"){
	command(":( "+getuid(me));
        me->set("th_killer", 1);
        kill_ob(me);
        return 1;
        }
        return 0;
}

int do_divine(string arg)
{
        object ob, where, env, me = this_player();
        string region;
	
	if (!me->query_temp("zhanbu_bagua"))
		return 0;

        if( !living(this_object()) )
                return notify_fail("��....����Ȱѳ�ӢŪ����˵��\n");

        if( this_object()->is_busy() )
                return notify_fail("��Ӣ˵�������Ե�һ�¡�\n");

	if(this_object()->query("jing") < 50)
                return notify_fail("��Ӣ���ڵľ���״���޷�ռ����\n");

	if (!arg) return notify_fail("��Ҫռ��˭��λ�ã�\n");

        if( !(ob = find_player(arg)) )
        if( !(ob = find_living(arg)) )
	        return notify_fail("��Ӣ�����㣺����û����ˡ�\n");
	if ( arg == "mariner" ) return notify_fail("��Ӣ�����㣺����û����ˡ�\n"); 
	        
        if( ob == me )
	        return notify_fail("ռ���Լ���λ�ã�û�����Ҫ�ɡ�\n");
	        
        if( ob == this_object() )
	        return notify_fail("Ҫ��Ӣռ����Ӣ��û����ɡ�\n");

	        write("\n�������Գ�Ӣ˵�����鷳��������ռ��"+ob->name()+"�����ڡ�\n\n");
        tell_room( environment(me), "\n"+me->name() + "�����Գ�Ӣ˵��Щ����\n", ({ me, this_object() }) );

	message_vision(CYN"��Ӣ����һֻ����������������Ĵָ�����������������ӡ���������î�������ȡ��硢δ���ꡢ�ϡ��硢��\n������λ��ϸ��������������\n\n"NOR, me);
	me->start_busy(1);

	if( !(where = environment(ob)) ) {
		command("consider");
	        return notify_fail("��Ӣ�����㣺����������޷��ҵ���\n");
		}
        if( !wizardp(me) && wizardp(ob) ) {
		command("consider");
		return notify_fail("��Ӣ˵����������λ��ʦ��СŮ��ռ�������ġ�\n");
		}
        if( strsrch(file_name(where), "/d/") != 0
        ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) {
        	command("doubt xiang shi");
                return notify_fail("��Ӣ�����㣺����������޷��ҵ���\n");
		}

	env = environment(me);

	if( me->query_kar() > ob->query_kar()/3 + random(ob->query_kar()*2/3) ) {
	
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")������"+region+""+where->query("short")+"��");
		if( random(me->query("kar")) < ob->query("kar") )
                tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......������"+me->query("name")+"("+me->query("id")+")��\n"NOR);
	} 
	
	else if( me->query_kar() > random(ob->query_kar()/2) ) {
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")������"+region+"һ����");
	 	if( random(me->query("kar")) < ob->query("kar"))
                tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......������"+me->query("name")+"("+me->query("id")+")��\n"NOR);

	} else {
	command("blush");
	command("say �Բ��𡭡�СŮ��ѧ�մ�ǳ��"+ RANK_D->query_respect(me) +"�ĸ�Ե�ֲ��Ǻܺã������㲻��������");
	}
	
	add("jing",-50);
	me->delete_temp("zhanbu_bagua");
        set("zhanbu_done/"+me->query("id"),1);
        call_out("wait_zhanbu", 900, me);
	return 1;
}

void wait_zhanbu(object me)
{
        delete("zhanbu_done/"+me->query("id"));
}

int accept_object(object who, object ob)
{
        object me = this_player();
        string tongmen;
	if (me->query("gender") == "����") tongmen = "ʦ��";
	else  if (me->query("gender") == "Ů��") tongmen = "ʦ��";

        if (ob->query("name") !="������" ) 
		return 0;
	if (query("zhanbu_done/"+me->query("id")))
                return notify_fail("��ղ��Ѿ��ҳ�Ӣռ�����ˡ�\n");

        if(me->query("combat_exp") < 10000)
                return notify_fail("��ľ���̫���ˣ��޷�����ռ����\n");
		
        if (ob->query("name") =="������" && (int)me->query_skill("qimen-dunjia",1) > 90 && me->query("family/master_name") == "��ҩʦ"){
                tell_object(who, "��Ӣ΢Ц����"+tongmen+"����ʤ�С�ã��αض��һ���ء�\n");
                return 0;
                }
        if (ob->query("name") =="������" && me->query("family/master_name") == "���ַ���"){
                tell_object(who, "��Ӣ˵�������ǽ��ַ����ĵ��ӡ����Ҿ��������ռ���ġ�\n");
                return 0;
                }


        call_out("accept_obj", 1, who, ob);
        return 1;
}

int accept_obj(object who, object ob)
{
        object me = this_player();
        string tongmen;

	if (me->query("gender") == "����") tongmen = "ʦ��";
	else  if (me->query("gender") == "Ů��") tongmen = "ʦ��";
	
        if(me->query("combat_exp") < 10000)
                return notify_fail("��ľ���̫���ˣ��޷�����ռ����\n");

	if (query("zhanbu_done/"+me->query("id")))
                return notify_fail("��ղ��Ѿ��ҳ�Ӣռ�����ˡ�\n");
        if (ob->query("name") !="������" ) 
		return 0;
        if (ob->query("name") =="������" && (int)me->query_skill("qimen-dunjia",1) > 90 && me->query("family/master_name") == "��ҩʦ"){
                tell_object(who, "��Ӣ΢Ц����"+tongmen+"����ʤ�С�ã��αض��һ���ء�\n");
                return 0;
                }
        if (ob->query("name") =="������" && me->query("family/master_name") == "���ַ���"){
                tell_object(who, "��Ӣ˵�������ǽ��ַ����ĵ��ӡ����Ҿ��������ռ���ġ�\n");
                return 0;
                }

        if (ob->query("name") =="������" ) 
        {		
		command("oh "+me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"��Ȼ�б������СŮ�Ӿ���һ�Ծ��ǡ�����֪"+ RANK_D->query_respect(me) +"Ҫռ��ʲ�᣿");
                who->set_temp("zhanbu_bagua",1);
                add("bagua_count",1);
//                call_out("destory", 1, ob);
		destruct(ob);

                return 1;
        }

        return 0;
}

string ask_bagua()
{
        string tongmen;
       	object me = this_player();
	if (me->query("gender") == "����") tongmen = "ʦ��";
	else  if (me->query("gender") == "Ů��") tongmen = "ʦ��";

        if (me->query("family/family_name") != "�һ���")
                return "�������Ǳ�����������������Ŷݼ�֮����";
                
        if (  present("tie bagua", me) || me->query_temp("cy_bagua"))
                return "�š�����Ӧ�����������˰ɣ�";
                
        if (me->query_skill("qimen-dunjia", 1) < 60 || me->query_skill("bitao-xuangong", 1) < 60)
                return "�����㻹���Ǻ���Ҫ�����԰ɣ�";

        if (query("bagua_count") < 1){
		command("consider");
                return "������û�������ԡ�";
	}


	add("bagua_count", -1);
        new("/d/taohua/obj/bagua")->move(me);
        me->set_temp("cy_bagua",1);
	command("nod");
        message_vision("��Ӣ��$Nһö�����ԡ�\n", me);
        if (query("bagua_count") < 1){
		if (me->query("family/master_name") == "��ҩʦ") 
		command ("say "+tongmen+"����������һö��������Ŷ��");
		else  command("say "+ RANK_D->query_respect(me) +"����������һö��������Ŷ��");
	}

	return "½ʦ������Ҳ�м�ö�����ԣ�ƽ��Ҳ���������á�";

}


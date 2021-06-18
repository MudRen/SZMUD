/* /kungfu/class/movie/npc/zhaodai
** ��Ʊ���д�
** created by yujie
** created in 11/2001
*/

#include <ansi.h>
inherit NPC;

#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define CPNUM "/data/movie/caipiao/cpnum"
#define CPSYS "/adm/single/cpsys"
#define JIANGDATA "/data/movie/caipiao/jiangdata"
#define NUMBAN "/data/movie/caipiao/numban"
#define TYPEJIANG "/data/movie/caipiao/typejiang"
#define PINANG "/kungfu/class/movie/obj/pinang"

#include <inttostr.h>

nosave string *jdata;

nosave string *typejiang;

string ask_pinang();

void create()
{
        set_name("�д�", ({ "zhao dai","zhaodai" }));
        set("title","��Ʊ��");
        set("long", "��Ʊ����Ƹ�д���������ϵ����������\n");
        set("gender", "����");
        set("age", 25);
        set("max_jing", 200);
        set("max_qi", 200);

        set("combat_exp", 0);
        set("shen_type", 1);

        set("inquiry", ([
                "��Ʊ" : "��ӵ�еĲ�Ʊ���Խ�����������Խ�������н��һ�֪ͨ��������������\n",
                "Ƥ��" : (:ask_pinang:),
                "��Ʊ��": "�����Ǹ����и�����Ʊ�;��п������Խ�����������е���\n",
        ]));

        setup();
}

int query_jiangdata()
{
	string msg;
	if (file_size(JIANGDATA)<1)
		return 0;

	msg = read_file(JIANGDATA);
	jdata = explode(msg,"*");
	return 1;

}

int query_typejiang()
{
	string msg;

	if (file_size(TYPEJIANG)<1)
		return 0;

	msg = read_file(TYPEJIANG);
	typejiang = explode(msg,"*");
	return 1;
}

int accept_object(object me, object ob)
{
	object thisob = this_object();
	object where;
	int i ,zhong ,num ,thisnum;
	string jpin;
	object boss;

	where = environment(thisob);

	if (base_name(where)!= "/kungfu/class/movie/caipiaohang")
	{	command("say ���ǵ��һز�Ʊ����˵�ɣ�");
		return 0;
	}

	if (base_name(ob) != CAIPIAO )
	{	command("say ������������");
		return 0;
	}

	if ( query_jiangdata() == 0)
	{	command("say ���ڻ�û�п���������ʱ���⹫��������ϵĿ�����Ϣ��");
		return 0;
	}

	zhong = 0;

	thisnum = ob->query("number");

	if (thisnum == 0)
	{	command("say ������һ�ŷ�Ʊ���������˰ɡ�");
		return 0;
	}

	for(i=1; i<sizeof(jdata); i++)
		if (sscanf(jdata[i],"%s@%d@",jpin,num) == 2)
			if (num == thisnum)
			{	zhong = 1;
				break;
			}

	if (zhong == 0)
	{	command("say �ܿ�ϧ�������ŵĺ��벻�Ǳ��ڵ��н����룬���ѯ�����ϵ��н����롣");
		return 0;
	}

	CPSYS->add_type(tostring(i),me->query("id"),"0");
	message_vision(HIG"$N����$n����˵������ϲ�㣬�����˱��θ�����Ʊ������"+chinese_number(i)+"�Ƚ���\n"NOR,thisob,me);
	message_vision(HIG"$N����$n����˵������Ľ�Ʒ�ǣ�"+jpin+"���һ�����֪ͨ��������Ϊ��佱��\n"NOR,thisob,me);
        CHANNEL_D->do_channel(this_object(), "sys", me->name() + "---"+ me->query("id")+"����˱��ڸ�����Ʊ�������"+chinese_number(i)+"�Ƚ���\n");
        CHANNEL_D->do_channel(this_object(), "sys", "����ʦ�Ǿ������Ϊ���佱���ǵð���������Ǻ�--mark");
        if ( objectp (boss = present("boss",where)))
        {	CHANNEL_D->do_channel(boss, "chat", me->name() + "��"+ me->query("id")+"������˱��ڸ�����Ʊ�������"+chinese_number(i)+"�Ƚ���\n");
        	CHANNEL_D->do_channel(boss, "chat", me->name()+"�Ľ�Ʒ�ǣ�"+jpin+ "�����ǻᾡ��Ϊ���佱����л��ҵĲ��롣\n");
        }

        return 1;
}

string ask_pinang()
{
	object me = this_player();
	object nang;

/*

	if (me->query("get_pinang"))
		return "���Ѿ��ù�Ƥ���ˣ���������˳����½�����ʱ���ֻ��Զ������ġ�\n";
*/
        if (present("pi nang",me))
                return "�������Ѿ���һ��Ƥ���ˡ�\n";

	nang = new(PINANG);
	nang ->set("owner",me->query("id"));
        me->set("get_pinang",1);
	nang ->move(me);
	message_vision("$N�ݸ�$nһ������Ƥ�ҡ�\n",this_object(),me);
	return "�Ժ���Ĳ�Ʊ�Ϳ��ԷŽ�Ƥ����˳���Ϸ�������������ᶪʧ�ˡ�\n�ǵ��������ǵĹ��棬��ʱ���鿴���Ƿ��н���ף����ˣ�\n";
}

// Code of ShenZhou
// chu, 3/8/99
#include <ansi.h>

inherit NPC;

string ask_qianzhu();
string ask_he();
string ask_lian();

string *qianzhu_message = ({
    "ǧ����������һ�Ŷ���, ��ʵ������ָ��, �ڹ�, �Ṧ, �м�����, һͨ��ͨ��\n",
    "��ǧ�����ּ�Ϊ��ʱ����, �������֮�����ɡ�\n",
    "ǧ��������������Ϊ����, Ҫ����Ϊ�˱���, �ҲŲ����ء�\n",
    "ǧ��������������, ��Խ������Խ����, ��Ҳ�������˰���ֻ������ѡ�\n",
    "����ǧ������ʱ�������, ����һ��������Ϊ�������ɡ�\n",
    "��������ֻ֪�����ɱɱ, ʵս������ḻ, ������ô�κε����ҵ�ǧ������?\n",
    "������ǧ�����ֵ�, ֻ�󶾹���տ, ��ʵս���鵹ûʲô��ϵ��\n",
    "ǧ������һ��ʩչ, ��ҩ�ɾ�, ֻ���ж����Լ��������������⡣\n",
    "ǧ�����������ҵļҴ��书, ��˵ûʲô����, �ɵ���������, �����޼���Ҳ����ס��һָ��\n",
    "����ǧ�������Ժ���ò����, ���ǲ���˵�ˡ�\n",
    "Ҫ˵��������, ������ǧֻ����Ҳ����ࡣ\n",
    "����������ֻ��֩���Ժ�ͻϮ(tuxi)���˵�Ч���ɾ������ˡ�\n",
});

void create()
{
        set_name("����", ({ "yin li", "yin", "li" }) );
        set("age", 18);
        set("gender", "Ů��");
  
        set("long", "���Ǹ�ʮ�߰������Ů�����β�ȹ��������ڣ����ϼ������ף�\n"
	"����͹͹�����ü��ǳ�ª��ֻ��һ������������ɣ����Ҳ���������㡣\n");
        set("attitude", "peaceful");

        set("combat_exp", 1800000);
        set("shen", -1000000);
	set_skill("qianzhu-wandu", 250);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("finger", 100);
  	map_skill("force", "qianzhu-wandu");
  	map_skill("dodge", "qianzhu-wandu");
  	map_skill("parry", "qianzhu-wandu");
  	map_skill("finger", "qianzhu-wandu");
  	prepare_skill("finger", "qianzhu-wandu");

	set("max_neili", 2000);
	set("neili", 2000);
	set("eff_qi", 1000);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jing", 1000);
	set("eff_jing", 1000);
	set("jing", 1000);
	set("max_jingli", 1000);
	set("eff_jingli", 1000);
	set("jingli", 1000);

	set("inquiry", ([
	    "ǧ������" : (: ask_qianzhu :),
	    "����" : "��, ��Ҫ�����¸��ı��������Ӹ������ú�����\n",
	    "��Ұ��" : "�����ҵ���\n",
	    "������" : "������үү��\n",
	    "������" : "�����ҹùá�\n",
	    "������" : "��, ����ȥ��˹����\n",
	    "��Ҷ����" : "��Ҷ������Ҳû������\n",
	    "����ţ" : "��, �����ҽ��, Ҫ������, ��Ҷ����Ҳ��������\n",
	    "���ѹ�" : "��, �ѹõĶ����Ǽ��ߵ�, ���ҵ�ǧ������ȴҲ����һ����\n",
	    "������" : "С�����˳���Ư��, �����۲���ô�á�\n",
	    "����" : "�Թ����Ļ�����, ���������\n",
	    "���޼�" : "��û���ĵġ����Ķ���������, �ҵ������Ҳ�������\n",
	    "����" : (: ask_he :),
	]));
        setup();
}

string ask_qianzhu() {
    object he, player = this_player(), me=this_object();
    int flags, level, idx;

    if (player->is_busy()) {
	if (player->query_busy() < 5) player->start_busy(5);
	return "����������������û��������˵�İ���\n";
    }

    flags = player->query_temp("qianzhu-wandu/flags");
    level = player->query_skill("qianzhu-wandu", 1);

    if (flags >= 1023 && level < 10) {
	command("say �ð�, ������ô����, �Ҿͽ������Ź���ɡ�\n");
        player->set_skill("qianzhu-wandu", 10);
	message_vision("$Nָ����$nһЩ������ǧ�����֡�\n", me, player);
        return "ʦ�������, ���п�����, �������Լ�������\n���û�н��У�����������Ҫ��\n";
    }else {
	player->start_busy(1+random(3));
        idx = random(sizeof(qianzhu_message));
	if (idx < 10) {
	    flags = flags | (1 << idx);
   	}
	player->set_temp("qianzhu-wandu/flags", flags);
	return qianzhu_message[idx];
    }
}

string ask_lian() {
    object player=this_player();
    int    checking, times;

    log_file("qianzhu-wandu", sprintf("%s: %s(%s) asked for bug\n",
				      ctime(time()), player->name(1),
					geteuid(player)));
    return 0;
    checking = player->query("qianzhu-wandu/checking");
    times = player->query_temp("qianzhu-wandu/ask_times");

    if (times < 100-checking) {
	times++;
	player->set_temp("qianzhu-wandu/ask_times", times);
	return 0;
    }
    checking ++;
    player->set("qianzhu-wandu/checking", checking);
    player->set_temp("qianzhu-wandu/ask_times", 0);
    return "���������£�ֻ�������ˡ�\n";
}

string ask_he() {
    object player=this_player();
    object he;

    if (player->query_skill("qianzhu-wandu", 1) < 10) {
	return "�����ز���ʶ, ����Ҳ��ð��ô��\n";
    }

    if (objectp(present("jin he", player))) {
	return "���Ѿ��н����ˡ�\n�����Ҹ�ƫƧ������, ץһֻ��֩��, �Լ��Ϳ�����������\n";
    }
    he = new ("/d/qilian/obj/jinhe");
    he->move(player);
    message_vision("$N��$nһ�����С�\n", this_object(), player);
    return "��ô��ô��С��, �ð�, ���ٸ���һ����\n";
}


//Cracked by Roath
inherit NPC;
#include "/d/beijing/npc/bjnpc.h"

void set_random_name();
void set_random_role();
void set_random_status();
void set_carried_items();
void set_inquiry();

mapping inq;

void create()
{

    // set_random_name();	// set_name
    set("gender", "����");
    set("age", 20+random(40));
    set("attitude", "friendly");
    set_random_status(); // gifts, skills
    set_random_role();	// long, chat_msg
    set("chat_chance", 10);
    setup();
    inq = ([ "here" : "������Ǿ��ǰ����������ǽ����ض�����" ]);
    set_carried_items();	// cloth etc
    set_inquiry();
    set("inquiry", inq);
}

// the talk messages
void set_inquiry()
{
    switch (query("role")) {
    case "bird":
	inq["����"] = "�����������ǹ������������ġ�";
	inq["��"] = "����ֻ��˿ȸ�Ѿ�����������";
	break;
    case "chess":
	inq["����"] = "����ʲô���ʵģ����Ӻ��罫ʿ�೵���ڱ���";
	inq["����"] = "�ٺ٣���÷����ʲô�ģ��ۿɲ�����һ�ס�";
	break;
    case "arob":
	inq["ǹ��"]= "�͹٣�����������ڵ�����ǹ������";
	break;
    }
}

// cloth to wear etc, default is ����
void set_carried_items()
{
    switch (query("role")) {
    case "bird":
	carry_object("/clone/armor/changpao")->wear();
	break;
    default:
	carry_object("/clone/armor/cloth")->wear();
	break;
    }
}

// The definition of a role.
// make sure you have "role" set, so that other functions can know
// what kind of randomnpc we are dealing with.
// Fill in the long desc and random chat messages is enough.
void set_random_role()
{
    switch (random(8)) {
    case 0:
    case 1:
    case 2:
	set("role", "chess");
	set_name("�����", ({"xiaqi"}));
        set("long", "����һ���ڽ�ͷ������������ˡ�\n");
	set("chat_msg", ({
	    name()+"̾�˿�����������ͷ�����Ҹ������嶼�Ҳ�����\n",
	    name()+"�����Ц�����������������µû������ɣ���һ�̣�\n",
	    (: random_walk :),
 	}));
	break;
    case 3:
    case 4:
	set_name("�����", ({"liuniao"}));
	set("role", "bird");
        set("long", "����һ���ڽ�ͷ��������ˡ�\n");
	set("chat_msg", ({
	    name()+"���˸����ڣ������������С��գ��գ�ۡ�\n",
	    name()+"���˻����������ûؼ�ඡ�\n",
	    (: random_walk :),
 	}));
	break;
    case 5:
	set_name("��ˣ��", ({"zashua"}));
	set("role", "arob");
        set("long", "����һ���ڽ�ͷˣǹ���յġ�\n");
	set("chat_msg", ({
	    name()+"�����е���С�ĸ���ү���밲�ˣ���Ǯ������Ǯ�������˵������˳���\n",
	    name()+"��������������������������ǹ�����ġ�\n",
	    (: random_walk :),
 	}));
	break;
    case 6:
    case 7:
    default:
	set_name("�����ӵ�", ({"baqi zidi", "baqi"}));
	set("role", "baqi");
        set("long", "����һ�������ӵܣ����Ż������������ֺ��С�\n");
	set("chat_msg", ({
	    name()+"������������ô�������갡��\n",
	    name()+"ü��ɫ���˵�����٣���������¥�Ǹ����ְ���\n",
	    (: random_walk :),
 	}));
	break;
    }
}

// Randomly sets some skill levels and combat_exp
void set_random_status()
{
    int lvl = random(40)+30;
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("max_qi",lvl*20);
    set("eff_qi",lvl*20);
    set("qi",lvl*20);

    set("max_jing",lvl*15);
    set("eff_jing",lvl*15);
    set("jing",lvl*15);

    set("jingli", lvl*20);
    set("max_jingli",lvl*20);
    set("neili", lvl*20);
    set("max_neili",lvl*20);

    set("shen_type",1);
    set("combat_exp", lvl*lvl/5*lvl);

    set_skill("force", lvl);
    set_skill("dodge", lvl);
    set_skill("parry", lvl);
}

// set a random name 
void set_random_name()
{
    mixed lastnamelist=({
    ({"��", "zhao"}), ({"Ǯ", "qian"}),  ({"��", "sun"}),   ({"��", "li"}),    
    ({"��", "zhou"}), ({"��", "wu"}),    ({"֣", "zheng"}), ({"��", "wang"}), 
    ({"��", "feng"}), ({"��", "chen"}),  ({"��", "wei"}),   ({"��", "gao"}),   
    ({"��", "yun"}),  ({"��", "zhang"}), ({"��", "liu"}),   ({"��", "ma"}),
    });

    mixed middlenamelist=({
    ({"��", "qing"}), ({"��", "bao"}),  ({"��", "zhong"}), ({"��", "cheng"}),
    ({"��", "ji"}),   ({"��", "bi"}),   ({"��", "jin"}),   ({"��", "ren"}),
    ({"��", "bo"}),   ({"��", "ru"}),   ({"��", "yin"}),   ({"��", "han"}),
    });

    mixed firstnamelist=({
    ({"��", "nian"}), ({"ɽ", "shan"}),  ({"ˮ", "shui"}), ({"��", "tian"}),
    ({"��", "tian"}), ({"��", "guang"}), ({"��", "gu"}),   ({"��", "hai"}),
    ({"��", "wen"}),  ({"��", "wu"}),    ({"֮", "zhi"}),  ({"��", "di"}),
    });

    string l_c, l_e, f_c, f_e, m_c, m_e;
    int i;

    i = random(sizeof(lastnamelist));
    l_c = lastnamelist[i][0];
    l_e = lastnamelist[i][1];

    i = random(sizeof(middlenamelist));
    m_c = middlenamelist[i][0];
    m_e = middlenamelist[i][1];

    i = random(sizeof(firstnamelist));
    f_c = firstnamelist[i][0];
    f_e = firstnamelist[i][1];

    set_name(l_c+m_c+f_c, ({l_e+" "+m_e+f_e, l_e}));
}

//Cracked by Roath
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97

inherit NPC;

int auto_perform();

void create()
{
        set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "��ָ��ؤ");
        set("gender", "����");
        set("age", 75);
        set("long",
"��һ�ų����������΢�룬���ִ�ţ������·���һ����һ��Ĵ����˲�����
ȴϴ�øɸɾ��������ϸ��Ÿ������Ĵ��«��\n");
        set("attitude", "peaceful");
        
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 30);
        
        set("rank", 10);
        
        set("chat_chance", 10);
        set("chat_msg", ({
"���߹�˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����ʯ
�ڡ�\n",
"���߹�ͻȻ���η���˫�ƾӸ�����һ�С��������졹���ڵ��Ϸ���
һ�����졣",
"���߹�����һ�С����������Ѹ���ޱȵ������ұߵ�һ���ʯ����
ʯ����ķ���������\n",
"���߹�˫��ʩ��һ�С��轥��½�����������ŷ�����ջӳ����Ʒ��
���������˼�����\n",
"���߹����ƾ۳�ȭ״������һ�С�Ǳ�����á�������ǰ�Ƴ���������
�������Ϸ�ʹ��\n",
"���߹�ʩ��һ�С�����󴨡������Ʋ���������������ߵ�һ���ʯ��\n",
"���߹�ʹ����ͻ�������������ƴӲ����ܵĽǶ����ұߵ�һ���ʯ��
����\n",
"���߹����һ����˫��ʹ�����𾪰��������һ�а����ʯ�ڡ�\n",
"���߹�ʹ������Ծ��Ԩ��������ߵ�һ���ʯ�������ơ�\n",
"���߹����λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ�����ұߵ�һ��
��ʯ��\n",
"���߹�ʹ������Ծ��Ԩ�������η���˫�Ʋ���һ������ߵ�һ���
ʯ���¡�\n",
"���߹�˫������ʹ����ʱ����������ʯ���������¡�ÿһ�¶����
ʯ������һ�ϡ�\n",
"���߹�ʹ�������Ʋ��꡹�����Ʒ�ס��·������бб������ʯ�ڡ�\n",
"���߹�ʹ�����������ڡ���˫��������������ұߵ�һ���ʯ��\n",
"���߹�����һת��ͻȻ�۵�ʯ��ǰ��һ�С���ս��Ұ��������ߵ�һ���ʯ��\n",
"���߹��Ż��󿪣�һ�С���˪���������ұߵ�һ���ʯ��ȥ��\n",
"���߹�ʹ��������ެ����˫���������ϻ�����ߵ�һ���ʯ��\n",
"���߹����ƻ��أ�����ʹһ�С�������β�����»ζ��Ż����ұߵ�һ���ʯ��\n",
        }));
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        
        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        
        set("combat_exp", 900000);
        set("score", 200000);
         
        set_skill("force", 180);             // �����ڹ�
        set_skill("huntian-qigong", 180);    // ��������
        set_skill("strike", 180);            // �����Ʒ�
        set_skill("xianglong-zhang", 180);   // ����ʮ����
        
        set_skill("hand", 180);              // �����ַ�
        set_skill("shexing-diaoshou", 200);  // ���ε���
        set_skill("dodge", 200);             // ��������
        set_skill("xiaoyaoyou", 200);        // ��ң��
        set_skill("parry", 180);             // �����м�
        set_skill("stick", 200);             // ��������
        set_skill("dagou-bang", 200);        // �򹷰���
        set_skill("begging", 100);           // �л�����
        set_skill("checking", 100);          // ����;˵
        set_skill("training", 120);          // Ԧ����
        set_skill("digging", 100);
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");
        
        create_family("ؤ��", 17, "����");
        setup();
        
        carry_object("/d/gaibang/obj/yuzhu-zhang");
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say �⡸�����С��Ĺ�ʫͼ�⣬�����Ź������������
����ѧ�ذ£��Ϸ�߾����ǣ����Բ��ܲ�������ʮ֮һ�����Ļ��ܷ�
��ȥ����������¡� ");
}

#include "/kungfu/class/gaibang/auto_perform.h"


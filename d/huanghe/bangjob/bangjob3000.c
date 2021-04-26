// Code of ShenZhou
// /d/huanghe/bangjob/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "��å",
                "file"  :  "/d/city/npc/liumang",
                "area"  :  "���ݳ�����",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  6,
        ]),

        ([      "name"  :  "׳��",
                "file"  :  "/d/city/npc/man",
                "area"  :  "���ݳ�����",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "��˪��",
                "file"  :  "/d/city/npc/shuanghua",
                "area"  :  "���ݺ��ָ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "�ٸ�",
                "file"  :  "/d/city/npc/woman",
                "area"  :  "���ݳ�����",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "��ʮ��",
                "file"  :  "/d/city/npc/zhang15",
                "area"  :  "���ݽֱ߾ƹ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "�仨",
                "file"  :  "/d/village/npc/cuihua",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  2,
        ]),

        ([      "name"  :  "�ر�",
                "file"  :  "/d/village/npc/dibao",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  5,
        ]),

        ([      "name"  :  "��Ʀ",
                "file"  :  "/d/village/npc/dipi",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  2,
        ]),

        ([      "name"  :  "�ϴ���",
                "file"  :  "/d/village/npc/oldwoman",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "�",
                "file"  :  "/d/village/npc/poorman",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "С��å",
                "file"  :  "/d/village/npc/punk",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "�����",
                "file"  :  "/d/emei/npc/xiang-ke",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "С����",
                "file"  :  "/d/emei/npc/xiao_tufei",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "�����ٸ�",
                "file"  :  "/d/emei/npc/woman",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/emei/npc/puren",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/foshan/npc/pang",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/foshan/npc/shou",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/forest/npc/zhangma",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "С����",
                "file"  :  "/d/jiaxing/npc/xiaoguizi",
                "area"  :  "���˳�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "С����",
                "file"  :  "/d/qilian/npc/xlama",
                "area"  :  "����",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/quanzhou/npc/kuli",
                "area"  :  "Ȫ�ݸ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "��ף",
                "file"  :  "/d/quanzhou/npc/miaozhu",
                "area"  :  "Ȫ�ݸ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  4,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/shu-sheng",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/tiao-fu",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "��Ƥ",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "Ұ�ջ�",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "���¾�����һ�¡�",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "���¾�",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "�����޶�����",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "���������ᾭ",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "��ɽ����",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "��ʫѡ��",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  15,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "άĦ��",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "�����ְ�ʦ�ض���",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "����Ӣ����",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "�����������Ͼ�",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "����������Ͼ�",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

      
        ([      "name"  :  "����",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "����",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "�������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "��ȸ���侭",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "�������侭",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "��Ƥ��ҩ",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "�׾���ϵ��ƪ��",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        
        ([      "name"  :  "�ۺ����",
                "file"  :  "/d/city/obj/pink_cloth",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "�뷿Կ��",
                "file"  :  "/d/city/obj/gfkey",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  5,
        ]),

        ([      "name"  :  "�̾ջ�",
                "file"  :  "/d/city/npc/obj/juhua1",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  12,
        ]),

        
        ([      "name"  :  "���Ķ�ȹ",
                "file"  :  "/d/dali/npc/obj/byskirt",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  2,
        ]),

        

        ([      "name"  :  "��Ⱦ����",
                "file"  :  "/d/dali/obj/ccloth",              
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "̨�Ķ�ȹ",
                "file"  :  "/d/dali/npc/obj/tyduanqun",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "̨��ͷ��",
                "file"  :  "/d/dali/npc/obj/tyduanqun",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "������ɴ����",
                "file"  :  "/d/dali/npc/obj/tqcloth",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "���ù�",
                "file"  :  "/d/qilian/obj/klguan",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "­��",
                "file"  :  "/d/qilian/obj/lubo",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "��ͷ��",
                "file"  :  "/d/qilian/obj/rtlian",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "Ƥѥ",
                "file"  :  "/d/xingxiu/obj/pi-xue",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "����ɢ",
                "file"  :  "/d/xingxiu/obj/xxqingxin-san",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "ͭ��",
                "file"  :  "/d/xingxiu/obj/tonggu",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "ͭ��",
                "file"  :  "/d/xingxiu/obj/tonghao",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  3,
        ]),

       

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}




# Personal Asset Management System

## Requirements Freeze v0.1

Status: Frozen requirement baseline.

This document is the authoritative requirement reference for future
Codex development.

## 1. Product Positioning

This project is a local personal asset risk-management system.

It is not a normal bookkeeping application, trading terminal, automatic
investment advisor, or account aggregation service.

The system manages: - physical asset location; - current risk
exposure; - virtual money identity; - planned operations; - portfolio
state evaluation.

The system performs calculation, classification, tracking, simulation
and warning.

It does not predict markets, execute trades, or access private financial
accounts.

## 2. Core Asset Model

Three dimensions must remain separate:

### Physical Asset Container

Where money actually exists.

### Current Risk Exposure

What risk the money currently bears.

### Virtual Fund Identity

What the money is intended to do.

Future purpose must never change current risk classification.

## 3. Conservation Rules

Virtual allocations cannot exceed actual assets.

Each physical container's virtual allocations cannot exceed its real
balance.

Temporary unallocated states are allowed.

## 4. Quick Conversion

The system must support atomic conversions:

-   free cash -\> equity pending;
-   equity reduction -\> low risk;
-   equity reduction -\> cash;
-   fixed income -\> equity reserve;
-   watch zone -\> spending;
-   watch zone -\> investment.

Source and destination changes must succeed or fail together.

## 5. Event Separation

Separate:

-   real cash flow;
-   real position changes;
-   virtual identity changes.

Virtual identity changes do not alter total assets or risk exposure.

## 6. Pending Transactions

Support pending purchases, redemptions, transfers and settlements.

Money in transit cannot be counted twice.

## 7. Simulation

Support simulation before confirmation.

Simulation must not modify real records.

## 8. Risk Evaluation

Support: - target allocation; - tolerance range; - warning boundary; -
hard boundary.

Evaluate: - current state; - confirmed future state; - planned state.

Avoid false warnings caused by intermediate operations.

## 9. Strategy Help

Maintain separate local files:

-   strategy_help.md for human-readable strategy;
-   strategy_rules.yaml for machine-readable rules.

Support strategy version history.

## 10. Backup

Support: - local backup; - export; - restore; - migration.

## 11. Privacy Boundary

Future networking may only access public market information.

Never store: - bank information; - Alipay account information; -
brokerage account information; - credentials; - tokens; - private paths.

Never execute transactions.

## 12. Companion Cash Management Project

A separate cash management project may exist.

The two systems share only a sanitized concept:

Personal Usable Cash.

The investment system may export only confirmed non-investment usable
cash.

The cash project must not access investments or strategies.

Use one-way interface files.

## 13. Non Goals

v0.1 does not implement:

-   automatic trading;
-   market prediction;
-   private account synchronization;
-   automatic investment advice.

## 14. v0.1 Success Criteria

The first version must support:

1.  asset input;
2.  money identity classification;
3.  quick conversions;
4.  simulation;
5.  pending transaction tracking;
6.  allocation calculation;
7.  risk warnings;
8.  event history;
9.  conservation validation.

## Final Principle

The program manages mathematics and structure.

The user retains final decisions.
